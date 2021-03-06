/* ===================================================================
File: test1.c
Authors: Ricardo Riol gonzalez, Francisco de Vicente Lana

Main de pruebas para comprobar varias estrellas recursivas.
=================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afnd.h"

#define SHELLSCRIPT "\
#/bin/bash \n\
dot -Tgif salida_estrella_estrella_estrella_union_afnd_b_afnd_a.dot > test2.gif\n\
rm salida_estrella_estrella_estrella_union_afnd_b_afnd_a.dot\n\
"

int main(int argc, char **argv)
{
    AFND *p_afnd_l0;
    AFND *p_afnd_l1;
    AFND *p_afnd_l2;
    AFND *p_afnd_l3;
    AFND *p_afnd_l4;
    AFND *p_afnd_l5;

    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “1” */
    p_afnd_l1 = AFND1ODeSimbolo("a");
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “0” */
    p_afnd_l0 = AFND1ODeSimbolo("b");
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “0”+“1” */
    p_afnd_l2 = AFND1OUne(p_afnd_l0, p_afnd_l1);
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESIÓN ( “0”+”1” ) * */
    p_afnd_l3 = AFND1OEstrella(p_afnd_l2);
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESIÓN ( “0”+”1” ) * * */
    p_afnd_l4 = AFND1OEstrella(p_afnd_l3);
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESIÓN ( “0”+”1” ) * * * */
    p_afnd_l5 = AFND1OEstrella(p_afnd_l4);

    AFNDADot(p_afnd_l5);

     /* SE CALCULA EL CIERRE REFLEXIVO-TRANSITIVO DE TODOS LOS AUTÓMATAS */
    p_afnd_l5 = AFNDCierraLTransicion(p_afnd_l5);

    /********************************************************/
    fprintf(stdout, "SE MUESTRA EL AUTÓMATA FINITO CORRESPONDIENTE A LA EXPRESION \"1\" * A PARTIR DEL AUTÓMATA ASOCIADO CON \"1\" QUE YA SE MOSTRÓ ANTERIORMENTE\n");
    AFNDImprime(stdout, p_afnd_l5);
    
    /********************************************************/
    fprintf(stdout, "\tLA CADENA ab ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l5, "a");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDImprimeCadenaActual(stdout, p_afnd_l5);
    AFNDInicializaEstado(p_afnd_l5);
    AFNDProcesaEntrada(stdout, p_afnd_l5);

    AFNDInicializaCadenaActual(p_afnd_l5);
    fprintf(stdout, "\tLA CADENA bba TAMBIÉN ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDInsertaLetra(p_afnd_l5, "a");
    AFNDImprimeCadenaActual(stdout, p_afnd_l5);
    AFNDInicializaEstado(p_afnd_l5);
    AFNDProcesaEntrada(stdout, p_afnd_l5);

    AFNDInicializaCadenaActual(p_afnd_l5);
    fprintf(stdout, "\tLA CADENA aab TAMBIÉN ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l5, "a");
    AFNDInsertaLetra(p_afnd_l5, "a");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDImprimeCadenaActual(stdout, p_afnd_l5);
    AFNDInicializaEstado(p_afnd_l5);
    AFNDProcesaEntrada(stdout, p_afnd_l5);

    AFNDInicializaCadenaActual(p_afnd_l5);
    fprintf(stdout, "\tLA CADENA abababb TAMBIÉN ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l5, "a");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDInsertaLetra(p_afnd_l5, "a");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDInsertaLetra(p_afnd_l5, "a");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDInsertaLetra(p_afnd_l5, "b");
    AFNDImprimeCadenaActual(stdout, p_afnd_l5);
    AFNDInicializaEstado(p_afnd_l5);
    AFNDProcesaEntrada(stdout, p_afnd_l5);

    AFNDInicializaCadenaActual(p_afnd_l5);
    fprintf(stdout, "\tLA CADENA VACIA ES RECONOCIDA\n");
    AFNDImprimeCadenaActual(stdout, p_afnd_l5);
    AFNDInicializaEstado(p_afnd_l5);
    AFNDProcesaEntrada(stdout, p_afnd_l5);
    AFNDInicializaCadenaActual(p_afnd_l5);

    /********************************************************/
    AFNDElimina(p_afnd_l0);
    AFNDElimina(p_afnd_l1);
    AFNDElimina(p_afnd_l2);
    AFNDElimina(p_afnd_l3);
    AFNDElimina(p_afnd_l4);
    AFNDElimina(p_afnd_l5);
    /********************************************************************************/

    puts(SHELLSCRIPT);
    system(SHELLSCRIPT);

    return 0;
}
