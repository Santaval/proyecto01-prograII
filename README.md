# Searching for shelter in the flood

During the country's affectation by a tropical storm, the Comisión Nacional de Emergencias compiled information on the condition of the area, identifying the flooded areas and the areas that have remained above the water level.

To contribute to the emergency response, the Universidad de Costa Rica has asked students from the Escuela de Ciencias de la Computación e Informática to develop a system for identifying suitable areas to establish shelters. These should be located in the largest unaffected areas so that if the water level rises again, the shelters will remain safe.

There are currently satellite images marked by the CNE of large tracts of land, which is why a subroutine in C is required to receive a rectangular piece of land and indicate the suitable areas to establish a refuge.

To make sure that the subroutine does its job correctly, the team prepared some test cases. You must, in addition to the subroutine, write a program that tests it against the prepared cases. The data provided by the CNE consists in the entry of the dimensions of the land in rows and columns, followed by a sketch of the rectangular floor, where a capital X (X) represents a flooded area and a hyphen (-) indicates an area that is flooded. has remained above the water level.
#

<b> Ejemplo de entrada:</b>

```
5 8

XXX-XXXX
XX--XXXX
-XXXXX--
-XXX----
XXXXXX--
```

<b> Ejemplo de salida:</b>

```
1
XXX-XXXX
XX--XXXX
-XXXXXRR
-XXXRRRR
XXXXXXRR
```