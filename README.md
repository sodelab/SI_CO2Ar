# SI

Olaseni Sode, Jesus Ruiz, and Steve Peralta 'Theoretical investigation of the vibrational structure of the Ar-CO2 complex' 
Supporting Information

--------------------------------------------------------------------------------

Directory structure

```
project
│   README.md
│
└───coord
│    │    NC_TRANS
│    │    tshaped.xyz
│    │    tshaped.zmat
│    │    linear.xyz
│    │    linear.zmat
│    │    complex.tga
└───library
└───routine 
        └───cpp
        └───python
```

--------------------------------------------------------------------------------

coordinate transformation file required for the NITROGEN vibrational
structure routines; a linear transformation coefficients are included in 
the file in space delimited lines for each row of [T t], according to the 
following equation,

\vec{q}' = {\bf T} \vec{q} + \vec{t}.

NC_TRANS

--------------------------------------------------------------------------------

cartesian coordinates of the Ar-CO2 complex

*.xyz

--------------------------------------------------------------------------------

z-matrix coordinates of the Ar-CO2 complex

*.zmat

--------------------------------------------------------------------------------

directory for compiling the shared libraries mbCO2AR.cpp and mbCO2.cpp which are 
used to compute the PES for the CO2-Ar complex

library

--------------------------------------------------------------------------------

directory for compiling routines for computing the potential energy of CO2-Ar
configurations using cpp and python

routine

--------------------------------------------------------------------------------
