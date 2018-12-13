/* ===================================================================
File: test1.c
Authors: Ricardo Riol gonzalez, Francisco de Vicente Lana

Main de pruebas para comprobar varias concatenaciones y uniones encadenadas.
=================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afnd.h"

#define SHELLSCRIPT "\
#/bin/bash \n\
dot -Tgif salida_union_union_concatenacion_afnd_0_afnd_0_concatenacion_afnd_0_afnd_1_union_concatenacion_afnd_1_afnd_0_concatenacion_afnd_1_afnd_1.dot > imgs/test3.gif\n\
rm salida_union_union_concatenacion_afnd_0_afnd_0_concatenacion_afnd_0_afnd_1_union_concatenacion_afnd_1_afnd_0_concatenacion_afnd_1_afnd_1.dot\n\
"

int main(int argc, char **argv)
{
    AFND *p_afnd_l0;
    AFND *p_afnd_l1;
    AFND *p_afnd_l2;
    AFND *p_afnd_l3;
    AFND *p_afnd_l4;
    AFND *p_afnd_l5;

    AFND *p_afnd_l6;
    AFND *p_afnd_l7;

    AFND *p_afnd_l8;

    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “1” */
    p_afnd_l1 = AFND1ODeSimbolo("1");
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “0” */
    p_afnd_l0 = AFND1ODeSimbolo("0");
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESIÓN ( “0”+”0” ) */
    p_afnd_l2 = AFND1OConcatena(p_afnd_l0, p_afnd_l0);
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESIÓN ( “0”+”1” ) */
    p_afnd_l3 = AFND1OConcatena(p_afnd_l0, p_afnd_l1);
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESIÓN ( “1”+”0” ) */
    p_afnd_l4 = AFND1OConcatena(p_afnd_l1, p_afnd_l0);
    /* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESIÓN ( “1”+”1” ) */
    p_afnd_l5 = AFND1OConcatena(p_afnd_l1, p_afnd_l1);

    /* 00 + 01 */
    p_afnd_l6 = AFND1OUne(p_afnd_l2, p_afnd_l3);
    /* 10 + 11 */
    p_afnd_l7 = AFND1OUne(p_afnd_l4, p_afnd_l5);

    /* 00 + 01 + 10 + 11 */
    p_afnd_l8 = AFND1OUne(p_afnd_l6, p_afnd_l7);

    AFNDADot(p_afnd_l8);

     /* SE CALCULA EL CIERRE REFLEXIVO-TRANSITIVO DE TODOS LOS AUTÓMATAS */
    p_afnd_l8 = AFNDCierraLTransicion(p_afnd_l8);

    /********************************************************/
    fprintf(stdout, "SE MUESTRA EL AUTÓMATA FINITO CONSTRUIDO\n");
    AFNDImprime(stdout, p_afnd_l8);

    /********************************************************/
    fprintf(stdout, "\tLA CADENA 00 ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDImprimeCadenaActual(stdout, p_afnd_l8);
    AFNDInicializaEstado(p_afnd_l8);
    AFNDProcesaEntrada(stdout, p_afnd_l8);

    AFNDInicializaCadenaActual(p_afnd_l8);
    fprintf(stdout, "\tLA CADENA 01 TAMBIÉN ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDInsertaLetra(p_afnd_l8, "1");
    AFNDImprimeCadenaActual(stdout, p_afnd_l8);
    AFNDInicializaEstado(p_afnd_l8);
    AFNDProcesaEntrada(stdout, p_afnd_l8);

    AFNDInicializaCadenaActual(p_afnd_l8);
    fprintf(stdout, "\tLA CADENA 10 TAMBIÉN ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l8, "1");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDImprimeCadenaActual(stdout, p_afnd_l8);
    AFNDInicializaEstado(p_afnd_l8);
    AFNDProcesaEntrada(stdout, p_afnd_l8);

    AFNDInicializaCadenaActual(p_afnd_l8);
    fprintf(stdout, "\tLA CADENA 11 TAMBIÉN ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l8, "1");
    AFNDInsertaLetra(p_afnd_l8, "1");
    AFNDImprimeCadenaActual(stdout, p_afnd_l8);
    AFNDInicializaEstado(p_afnd_l8);
    AFNDProcesaEntrada(stdout, p_afnd_l8);

    AFNDInicializaCadenaActual(p_afnd_l8);
    fprintf(stdout, "\tLA CADENA VACIA SIN EMBARGO NO ES RECONOCIDA\n");
    AFNDImprimeCadenaActual(stdout, p_afnd_l8);
    AFNDInicializaEstado(p_afnd_l8);
    AFNDProcesaEntrada(stdout, p_afnd_l8);
    AFNDInicializaCadenaActual(p_afnd_l8);

    AFNDInicializaCadenaActual(p_afnd_l8);
    fprintf(stdout, "\tLA CADENA 000 NO ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDImprimeCadenaActual(stdout, p_afnd_l8);
    AFNDInicializaEstado(p_afnd_l8);
    AFNDProcesaEntrada(stdout, p_afnd_l8);

    AFNDInicializaCadenaActual(p_afnd_l8);
    fprintf(stdout, "\tLA CADENA 0011 NO ES RECONOCIDA\n");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDInsertaLetra(p_afnd_l8, "0");
    AFNDInsertaLetra(p_afnd_l8, "1");
    AFNDInsertaLetra(p_afnd_l8, "1");
    AFNDImprimeCadenaActual(stdout, p_afnd_l8);
    AFNDInicializaEstado(p_afnd_l8);
    AFNDProcesaEntrada(stdout, p_afnd_l8);

    /********************************************************/
    AFNDElimina(p_afnd_l0);
    AFNDElimina(p_afnd_l1);
    AFNDElimina(p_afnd_l2);
    AFNDElimina(p_afnd_l3);
    AFNDElimina(p_afnd_l4);
    AFNDElimina(p_afnd_l5);
    AFNDElimina(p_afnd_l6);
    AFNDElimina(p_afnd_l7);
    AFNDElimina(p_afnd_l8);
    /********************************************************************************/

    puts(SHELLSCRIPT);
    system(SHELLSCRIPT);

    return 0;
}
