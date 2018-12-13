/* ===================================================================
File: test5.c
Authors: Ricardo Riol gonzalez, Francisco de Vicente Lana
Test de prueba la funcion AFNDAAFND1o
=================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "afnd.h"

#define SHELLSCRIPT "\
#/bin/bash \n\
dot -Tgif salida_final_state_afl1.dot > imgs/test4.gif\n\
rm salida_final_state_afl1.dot\n\
"

int main(int argc, char **argv)
{
    /* DECLARACIÓN DE UN PUNTERO A UN AFND */
    AFND *p_afnd;
    AFND *afnd;

    /* INICIALIZACIÓN DE UN NUEVO AFND DE NOMBRE afl1 Y CON 8 ESTADOS Y
    2 SÍMBOLOS EN SU ALFABETO */
    p_afnd = AFNDNuevo("afl1", 4, 2);

    /* DEFINICIÓN DEL ALFABETO DEL AFND */
    AFNDInsertaSimbolo(p_afnd, "1");
    AFNDInsertaSimbolo(p_afnd, "0");

    /* DEFINICIÓN DEL CONJUNTO DE ESTADOS */
    AFNDInsertaEstado(p_afnd, "q0", INICIAL);
    AFNDInsertaEstado(p_afnd, "q1", INICIAL);
    AFNDInsertaEstado(p_afnd, "q2", FINAL);
    AFNDInsertaEstado(p_afnd, "q3", FINAL);

    /* DEFINICIÓN DE LAS TRANSICIONES NO LAMBDA */
    AFNDInsertaTransicion(p_afnd, "q0", "0", "q0");
    AFNDInsertaTransicion(p_afnd, "q0", "1", "q2");
    AFNDInsertaTransicion(p_afnd, "q1", "1", "q1");
    AFNDInsertaTransicion(p_afnd, "q1", "0", "q3");
    AFNDInsertaTransicion(p_afnd, "q2", "0", "q2");
    AFNDInsertaTransicion(p_afnd, "q2", "1", "q3");

    /** DEFINICIÓN DE LAS TRANSICIONES LAMBDA*/
    AFNDImprime(stdout, p_afnd);

    /**Hacemos que solo tenga un estado final y uno inicial*/
    afnd = AFNDAAFND1O(p_afnd);

    /** DEFINICIÓN DE LAS TRANSICIONES LAMBDA*/
    AFNDImprime(stdout, afnd);

    /*Dibujamos el automata*/
    AFNDADot(afnd);

    /** INDUCIMOS EL RESTO DE TRANSICIONES LAMBDA*/
    AFNDCierraLTransicion(afnd);

    /* SE ESTABLECE COMO ESTADO ACTUAL DEL AUTÓMATA EL INICIAL */
    p_afnd = AFNDInicializaEstado(p_afnd);


    /**Liberamos memoria*/
    AFNDElimina(p_afnd);
    AFNDElimina(afnd);

    puts(SHELLSCRIPT);
    system(SHELLSCRIPT);

    return 0;
}