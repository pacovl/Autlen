#!/bin/bash

dot -Tgif salida_afnd_0.dot > 0.gif
dot -Tgif salida_afnd_1.dot > 1.gif
dot -Tgif salida_concatenacion_afnd_1_afnd_1.dot > 2.gif
dot -Tgif salida_concatenacion_concatenacion_afnd_1_afnd_1_estrella_union_afnd_0_afnd_1.dot > 3.gif
dot -Tgif salida_union_afnd_0_afnd_1.dot > 4.gif
dot -Tgif salida_estrella_union_afnd_0_afnd_1.dot > 5.gif
dot -Tgif salida_estrella_afnd_1.dot > 6.gif

rm salida_afnd_0.dot
rm salida_afnd_1.dot
rm salida_concatenacion_afnd_1_afnd_1.dot
rm salida_concatenacion_concatenacion_afnd_1_afnd_1_estrella_union_afnd_0_afnd_1.dot
rm salida_union_afnd_0_afnd_1.dot
rm salida_estrella_union_afnd_0_afnd_1.dot
rm salida_estrella_afnd_1.dot