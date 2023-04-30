# Searching for shelter in the flood

<p> During the country's affectation by a tropical storm, the Comisión Nacional de Emergencias compiled information on the condition of the area, identifying the flooded areas and the areas that have remained above the water level.

To contribute to the emergency response, the Universidad de Costa Rica has asked students from the Escuela de Ciencias de la Computación e Informática to develop a system for identifying suitable areas to establish shelters. These should be located in the largest unaffected areas so that if the water level rises again, the shelters will remain safe.

There are currently satellite images marked by the CNE of large tracts of land, which is why a subroutine in C is required to receive a rectangular piece of land and indicate the suitable areas to establish a refuge.

To make sure that the subroutine does its job correctly, the team prepared some test cases. You must, in addition to the subroutine, write a program that tests it against the prepared cases. The data provided by the CNE consists in the entry of the dimensions of the land in rows and columns, followed by a sketch of the rectangular floor, where a capital X (X) represents a flooded area and a hyphen (-) indicates an area that is flooded. has remained above the water level.</p>
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

<p> 

For the CNE, it would be convenient for the subroutine to receive the land as a matrix and in it mark with a capital “r” (R) the cells belonging to the area where the refuge will be established. These will be all the zones belonging to the largest unflooded area. Two cells are considered part of the same zone if they are contiguous vertically or horizontally. It may happen that two or more zones are the same size. In this case, all must be marked in the matrix. The number of zones found must also be indicated on the first line of the start.

The test program must read the data to use. These can come from standard input or from a file. In case you want to use a file, its name will be provided on the standard input. Because the files can be very large, you can include a -b parameter indicating that the file is binary. In case it is a binary file, the format will be as follows:</p>



<table>
    <tr> 
        <td>Element</td>
        <td>Size</td>
    </tr>

<tr> 
    <td>Rows amount</td>
    <td>4 bytes unsigned</td>
</tr>

<tr> 
    <td>Columns amount</td>
    <td>4 bytes unsigned</td>
</tr>

<tr> 
    <td>Continious data matix</td>
    <td>Rows * colunms bytes</td>
</tr>

</table>



<p> 
Regardless of whether the input is provided in a binary file, the output must be generated in a text file. The test program should call the subroutine and print on the output the number of zones found and the resulting terrain with the marked zones. If the input was provided in a file, the output should also be a file, with the same name, appending the text “-out” to the file name. Otherwise, the output will need to be displayed on stdout.
</p>