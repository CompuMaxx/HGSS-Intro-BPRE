# HGSS-Intro-BPRE
Intro estilo HGSS para BPRE basada en el template de kaisermg5
https://github.com/kaisermg5/pokemon-intro-template


==============================================
Original README
==============================================

# pokemon-intro-template
A template to make making your custom pokemon intro easier. Working in pokemon fire red, at the moment.  


This is "not programmer" friendly way to make a custom intro for pokemon gba games.  
It is based on Shiny Quagsire's work (https://github.com/shinyquagsire23/FR-CrystalIntro)  

The contents in "pokeagb" are just a builded version of: https://github.com/Touched/g3headers  

#-----------------------------------------

Dependencies for building:  
-DevkitARM  
-Armips  
-Make  


You should write your code at "src/intro.c"  
Modify the line ".org 0x08800000" in "main.s", to your free rom address.  
Then put you rom named "BPRE0.gba" in the main directory.  
And execute make.  
A new rom named "rom.gba" should have appeared in the directory "build"  


#-----------------------------------------

There is also a GUI tool in the "tools" directory which allows you to easily make header files from images and raw data files.  
Dependencies:  
-python3  
-sip  
-PyQt5  
-Pillow  

#-----------------------------------------

Credits and thanks to:  
-Shiny Quagsire  
-Touched  
-FBI  
-knizz  
-cosarara97  
-Nintenlord  
