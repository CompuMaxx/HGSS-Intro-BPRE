
#include "headers/important.h"
#include "headers/functions.h"
#include "resources/backgrounds.h"
#include "resources/objetos.h"

const struct OamData hide_oam = {
    .x = -32,
    .y = -32,
    .affine_mode = 0,
    .priority = 0,
    .h_flip = 0,
    .v_flip = 0,
    .size = SIZE_64x64, 
};

const struct OamData centro_oam = {
    .x = 120,
    .y = 96,
    .affine_mode = 0,
    .priority = 2,
    .h_flip = 0,
    .v_flip = 0,
    .size = SIZE_64x64, 
};

const struct OamData izq_oam = {
    .x = 40,
    .y = 10,
    .affine_mode = 0,
    .priority = 0,
    .h_flip = 1,
    .v_flip = 0,
    .size = SIZE_64x64, 
};

const struct OamData der_oam = {
    .x = 200,
    .y = 10,
    .affine_mode = 0,
    .priority = 0,
    .h_flip = 0,
    .v_flip = 0,
    .size = SIZE_64x64, 
};


#define Sol 		0
#define Grama_1 	1
#define Grama_2 	2
#define Flor_1 		3
#define Flor_2 		4
#define Unown_1 	5
#define Unown_2 	6
#define Unown_3	7
#define Mano_1		8
#define Mano_2		9

bool intro_main()
{
	
	if (get_var(0) == 0) {
		if (get_time() == 0){
			set_bg_config();			// Carga la configuración de BG #0
			BG0VOFF = 0;		
			BG1VOFF = 0;	
			BG2VOFF = 0;		
			load_bg_pal(0, &BG_Pal, false);
		    load_sprite_pal(&OBJ_0Pal, 1, false);
		    load_sprite_pal(&OBJ_1Pal, 2, false);
			load_bg_data(0, &BG_0Tiles, &BG_0Map);
		} else if ((get_time() ==3 * SECOND)){ 
			load_bg_data(3, &BG_1Tiles, &BG_1Map);
			load_bg_data(2, &BG_2Tiles, &BG_2Map);		
			load_bg_data(1, &BG_3Tiles, &BG_3Map);		
		    load_sprite(&centro_oam, &OBJ_0Tiles, Sol, 1, 1, SPRITE_NO_ANIMATION);       
		}else if(get_time() == (302 * SECOND)/100) {	//Retardo 2/100 seg.
			BLDCNT = 0x81;
			BLDY = 1;		
		} else if (get_time() == (306 * SECOND)/100) {	//Retardo 4/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (308 * SECOND)/100) {	//Retardo 2/100 seg.
			BLDY = 2;		
		} else if (get_time() == (310 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (312 * SECOND)/100) {	//Retardo 2/100 seg.
			BLDY = 4;		
		} else if (get_time() == (313 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (318 * SECOND)/100) {	//Retardo 5/100 seg.
			BLDY = 5;		
		} else if (get_time() == (320 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (321 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (322 * SECOND)/100) {	//Retardo 1/100 seg.
			BLDY = 6;		
		} else if (get_time() == (328 * SECOND)/100) {	//Retardo 6/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (330 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (334 * SECOND)/100) {	//Retardo 4/100 seg.
			BLDY = 8;		
		} else if (get_time() == (336 * SECOND)/100) {	//Retardo 2/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (338 * SECOND)/100) {	//Retardo 2/100 seg.
			BLDY = 9;		
		} else if (get_time() == (340 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (343 * SECOND)/100) {	//Retardo 3/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (344 * SECOND)/100) {	//Retardo 1/100 seg.
			BLDY = 10;		
		} else if (get_time() == (348 * SECOND)/100) {	//Retardo 4/100 seg.
			BLDY = 12;		
		} else if (get_time() == (350 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (351 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (354 * SECOND)/100) {	//Retardo 3/100 seg.
			BLDY = 13;		
		} else if (get_time() == (358 * SECOND)/100) {	//Retardo 4/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (360 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (364 * SECOND)/100) {	//Retardo 4/100 seg.
			BLDY = 14;		
		} else if (get_time() == (366 * SECOND)/100) {	//Retardo 2/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (370 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (373 * SECOND)/100) {	//Retardo 3/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (374 * SECOND)/100) {	//Retardo 1/100 seg.
			BLDY = 15;		
		} else if (get_time() == (380 * SECOND)/100) {	//Retardo 6/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (381 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (384 * SECOND)/100) {	//Retardo 3/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (387 * SECOND)/100) {	//Retardo 4/100 seg.
			BLDCNT = 0x1E41;			//Valor = 0x1E41, Objetivo 1 BG0, Objetivo 2 BG1, BG y BG3, OBJ tipo de efecto: Transparencia
			BLDALPHA = 0x1010;			//Valor = 0x10 para Objetivo 1 y para Objetivo 2, Ninguno de los 2 objetivos tienen transparencia
			BLDALPHA = BLDALPHA - 2;
		} else if (get_time() == (391 * SECOND)/100) {	//Retardo 4/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (393 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (399 * SECOND)/100) {	//Retardo 6/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (403 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
			BLDALPHA = BLDALPHA - 2;
		} else if (get_time() == (406 * SECOND)/100) {	//Retardo 3/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (409 * SECOND)/100) {	//Retardo 3/100 seg.
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (413 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
			BLDALPHA = BLDALPHA - 2;
		} else if (get_time() == (414 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (419 * SECOND)/100) {	//Retardo 5/100 seg.
			BLDALPHA = BLDALPHA - 2;
		} else if (get_time() == (421 * SECOND)/100) {	//Retardo 2/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (423 * SECOND)/100) {	//Retardo 2/100 seg. 
			move_sprite(Sol, 0, -1);					
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (429 * SECOND)/100) {	//Retardo 6/100 seg.
			move_bg(3,0,-1);		
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (433 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (435 * SECOND)/100) {	//Retardo 2/100 seg.
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (436 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (438 * SECOND)/100) {	//Retardo 3/100 seg.
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (442 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (443 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (444 * SECOND)/100) {	//Retardo 1/100 seg.
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (448 * SECOND)/100) {	//Retardo 4/100 seg.
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (450 * SECOND)/100) {	//Retardo 2/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (452 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (453 * SECOND)/100) {	//Retardo 2/100 seg.
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (457 * SECOND)/100) {	//Retardo 4/100 seg.
			move_bg(3,0,-1);		
			BLDALPHA = BLDALPHA - 1;
		} else if (get_time() == (461 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (464 * SECOND)/100) {	//Retardo 3/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (471 * SECOND)/100) {	//Retardo 7/100 seg. 
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (472 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (479 * SECOND)/100) {	//Retardo 7/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (481 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (487 * SECOND)/100) {	//Retardo 6/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (491 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (494 * SECOND)/100) {	//Retardo 3/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (501 * SECOND)/100) {	//Retardo 7/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (502 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (509 * SECOND)/100) {	//Retardo 7/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (511 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (517 * SECOND)/100) {	//Retardo 6/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (521 * SECOND)/100) {	//Retardo 4/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (524 * SECOND)/100) {	//Retardo 3/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (531 * SECOND)/100) {	//Retardo 7/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (532 * SECOND)/100) {	//Retardo 1/100 seg.
			move_bg(3,0,-1);		
		} else if (get_time() == (539 * SECOND)/100) {	//Retardo 7/100 seg.
			move_bg(3,0,-1);		
			move_bg(2,0,-1);		
		} else if (get_time() == (541 * SECOND)/100) {	//Retardo 2/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (551 * SECOND)/100) {	//Retardo 10/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (561 * SECOND)/100) {	//Retardo 10/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (571 * SECOND)/100) {	//Retardo 10/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (581 * SECOND)/100) {	//Retardo 10/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (591 * SECOND)/100) {	//Retardo 10/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (601 * SECOND)/100) {	//Retardo 10/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (611 * SECOND)/100) {	//Retardo 10/100 seg.
			move_sprite(Sol, 0, -1);					
		} else if (get_time() == (612 * SECOND)/100) {	//Retardo 1/100 seg.
			load_bg_data(0, &BG_9Tiles, &BG_9Map);
			BLDCNT = 0x0;
			toggle_bg_displayed(2);
			toggle_bg_displayed(3);
			BG2VOFF = 0;
			BG2CNT = 0x1408;
			load_bg_data(2, &BG_4_1Tiles, &BG_4_1Map);		// Carga Ho-oh	
		} else if (get_time() == (797 * SECOND)/100) {		//Retardo 185/100 seg. 
			DISPCNT = DISPCNT + 0x100; 						// Habilita el blanco forzado
			DISPCNT = 0x1741;								// Cambia el video a modo 1
		} else if (get_time() == (990 * SECOND)/100) {
			fadescreen_white();  							// duración 16/100 seg
		} else if (get_time() == (1020 * SECOND)/100) {
			delete_sprite(Sol);
			DISPCNT = DISPCNT + 0x100; 						// Habilita el blanco forzado
			set_bg_config_1();								// Carga la configuración de BG #1
			BG0VOFF = 160;		
			BG1VOFF = 160;	
			BG2VOFF = 320;
			BG3VOFF = 0;
			clear_bgs();			
			load_bg_data_1(0, &BG_5Tiles, &BG_6Map);
			load_bg_data_1(1, &BG_7Tiles, &BG_7Map);
			load_bg_data_1(2, &BG_8_0Tiles, &BG_8_0Map);
			load_bg_data_1(3, &BG_5Tiles, &BG_5Map);
			DISPCNT = 0x1F40;								// Cambia el video a modo 0
		} else if (get_time() == (1030 * SECOND)/100) {
			unfadescreen();
		} else if (get_time() == ((1041) * SECOND)/100){	
			BG3VOFF = 65;		
		} else if (get_time() == ((1042) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1043) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1044) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1045) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1046) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1047) * SECOND)/100){
			BG3VOFF = 195;
		} else if (get_time() == ((1048) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1049) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1050) * SECOND)/100){
			BG3VOFF = 130;		
		    load_sprite(&izq_oam, &OBJ_1Tiles, Grama_1, 2, 1, SPRITE_NO_ANIMATION);       
		} else if (get_time() == ((1051) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1052) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1053) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1054) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1055) * SECOND)/100){
			BG3VOFF = 195;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1056) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1057) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1058) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1059) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1060) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1061) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1062) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1063) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1064) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1065) * SECOND)/100){
			BG3VOFF = 65;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1066) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1067) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1068) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1069) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1070) * SECOND)/100){
			BG3VOFF = 130;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1071) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1072) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1073) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1074) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1075) * SECOND)/100){
			BG3VOFF = 195;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1076) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1077) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1078) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1079) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1080) * SECOND)/100){
			BG3VOFF = 260;		
			delete_sprite(Grama_1);								
		} else if (get_time() == ((1081) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1082) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1083) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1084) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1085) * SECOND)/100){
			BG3VOFF = 65;		
		    load_sprite(&der_oam, &OBJ_1Tiles, Grama_2, 2, 1, SPRITE_NO_ANIMATION);       
		} else if (get_time() == ((1086) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1087) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1088) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1089) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1090) * SECOND)/100){
			BG3VOFF = 130;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1091) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1092) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1093) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1094) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1095) * SECOND)/100){
			BG3VOFF = 195;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1096) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1097) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1098) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1099) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1100) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1101) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1102) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1103) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1104) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1105) * SECOND)/100){
			BG3VOFF = 65;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1106) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1107) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1108) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1109) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1110) * SECOND)/100){
			BG3VOFF = 130;
			delete_sprite(Grama_2);
		} else if (get_time() == ((1111) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1112) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1113) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1114) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1115) * SECOND)/100){
			BG3VOFF = 195;		
		    load_sprite(&izq_oam, &OBJ_2Tiles, Flor_1, 2, 1, SPRITE_NO_ANIMATION);       
		} else if (get_time() == ((1116) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1117) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1118) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1119) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1120) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Flor_1, 0, 30);								
		} else if (get_time() == ((1121) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1122) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1123) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1124) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1125) * SECOND)/100){
			BG3VOFF = 65;		
			move_sprite(Flor_1, 0, 30);								
		} else if (get_time() == ((1126) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1127) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1128) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1129) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1130) * SECOND)/100){
			BG3VOFF = 130;		
			move_sprite(Flor_1, 0, 30);								
		} else if (get_time() == ((1131) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1132) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1133) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1134) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1135) * SECOND)/100){
			BG3VOFF = 195;		
			move_sprite(Flor_1, 0, 30);								
		} else if (get_time() == ((1136) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1137) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1138) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1139) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1140) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Flor_1, 0, 30);								
		} else if (get_time() == ((1141) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1142) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1143) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1144) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1145) * SECOND)/100){
			BG3VOFF = 65;
			delete_sprite(Flor_1);
		} else if (get_time() == ((1146) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1147) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1148) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1149) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1150) * SECOND)/100){
			BG3VOFF = 130;		
		    load_sprite(&der_oam, &OBJ_2Tiles, Flor_2, 2, 1, SPRITE_NO_ANIMATION);    
		} else if (get_time() == ((1151) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1152) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1153) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1154) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1155) * SECOND)/100){
			BG3VOFF = 195;	
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1156) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1157) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1158) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1159) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1160) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1161) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1162) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1163) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1164) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1165) * SECOND)/100){
			BG3VOFF = 65;	
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1166) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1167) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1168) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1169) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1170) * SECOND)/100){
			BG3VOFF = 130;		
		    load_sprite(&izq_oam, &OBJ_1Tiles, Grama_1, 2, 1, SPRITE_NO_ANIMATION);       
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1171) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1172) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1173) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1174) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1175) * SECOND)/100){
			BG3VOFF = 195;	
			move_sprite(Grama_1, 0, 30);								
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1176) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1177) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1178) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1179) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1180) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Grama_1, 0, 30);								
			delete_sprite(Flor_2);								
		} else if (get_time() == ((1181) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1182) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1183) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1184) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1185) * SECOND)/100){
			BG3VOFF = 65;	
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1186) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1187) * SECOND)/100){
			BG3VOFF = 195;	
		} else if (get_time() == ((1188) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1189) * SECOND)/100){
			BG3VOFF = 65;	
		} else if (get_time() == ((1190) * SECOND)/100){
			BG3VOFF = 130;		
		    load_sprite(&der_oam, &OBJ_1Tiles, Grama_2, 2, 1, SPRITE_NO_ANIMATION);
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1191) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1192) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1193) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1194) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1195) * SECOND)/100){
			BG3VOFF = 130;		
		    delete_sprite(Grama_1);
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1196) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1197) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1198) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1199) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1200) * SECOND)/100){
			BG3VOFF = 195;		
		    load_sprite(&izq_oam, &OBJ_2Tiles, Flor_1, 2, 1, SPRITE_NO_ANIMATION);
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1201) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1202) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1203) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1204) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1205) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Flor_1, 0, 30);								
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1206) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1207) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1208) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1209) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1210) * SECOND)/100){
			BG3VOFF = 65;		
			move_sprite(Flor_1, 0, 30);								
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1211) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1212) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1213) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1214) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1215) * SECOND)/100){
			BG3VOFF = 130;		
			move_sprite(Flor_1, 0, 30);								
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1216) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1217) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1218) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1219) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1220) * SECOND)/100){
			BG3VOFF = 195;		
		    load_sprite(&der_oam, &OBJ_2Tiles, Flor_2, 2, 1, SPRITE_NO_ANIMATION);
			move_sprite(Flor_1, 0, 30);								
			delete_sprite(Grama_2);								
		} else if (get_time() == ((1221) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1222) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1223) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1224) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1225) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Flor_1, 0, 30);								
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1226) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1227) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1228) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1229) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1230) * SECOND)/100){
			BG3VOFF = 65;		
			delete_sprite(Flor_1);								
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1231) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1232) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1233) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1234) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1235) * SECOND)/100){
			BG3VOFF = 130;		
		    load_sprite(&izq_oam, &OBJ_1Tiles, Grama_1, 2, 1, SPRITE_NO_ANIMATION);
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1236) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1237) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1238) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1239) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1240) * SECOND)/100){
			BG3VOFF = 195;		
			move_sprite(Grama_1, 0, 30);								
			move_sprite(Flor_2, 0, 30);								
		} else if (get_time() == ((1241) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1242) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1243) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1244) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1245) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Grama_1, 0, 30);								
			delete_sprite(Flor_2);								
		} else if (get_time() == ((1246) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1247) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1248) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1249) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1250) * SECOND)/100){
			BG3VOFF = 65;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1251) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1252) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1253) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1254) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1255) * SECOND)/100){
			BG3VOFF = 130;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1256) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1257) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1258) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1259) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1260) * SECOND)/100){
			BG3VOFF = 195;		
			move_sprite(Grama_1, 0, 30);								
		} else if (get_time() == ((1261) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1262) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1263) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1264) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1265) * SECOND)/100){
			BG3VOFF = 260;	
		    load_sprite(&der_oam, &OBJ_1Tiles, Grama_2, 2, 1, SPRITE_NO_ANIMATION);
			delete_sprite(Grama_1);								
		} else if (get_time() == ((1266) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1267) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1268) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1269) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1270) * SECOND)/100){
			BG3VOFF = 65;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1271) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1272) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1273) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1274) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1275) * SECOND)/100){
			BG3VOFF = 130;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1276) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1277) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1278) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1279) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1280) * SECOND)/100){
			BG3VOFF = 195;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1281) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1282) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1283) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1284) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1285) * SECOND)/100){
			BG3VOFF = 260;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1286) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1287) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1288) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1289) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1290) * SECOND)/100){
			BG3VOFF = 65;		
			move_sprite(Grama_2, 0, 30);								
		} else if (get_time() == ((1291) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1292) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1293) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1294) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1295) * SECOND)/100){
			BG3VOFF = 130;
			delete_sprite(Grama_2);
			BG3VOFF = 65;
			BG0VOFF = 128;		
			BG1VOFF = 160;	
			BG2VOFF = 288;			
		} else if (get_time() == ((1296) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1297) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1298) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1299) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1300) * SECOND)/100){
			BG3VOFF = 195;
			BG0VOFF = 96;		
			BG1VOFF = 128;	
			BG2VOFF = 256;			
		} else if (get_time() == ((1297) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1298) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1299) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1296) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1300) * SECOND)/100){
			BG3VOFF = 260;
			BG0VOFF = 64;		
			BG1VOFF = 96;	
			BG2VOFF = 224;			
		} else if (get_time() == ((1301) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1302) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1303) * SECOND)/100){
			BG3VOFF = 195;		
		} else if (get_time() == ((1304) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1305) * SECOND)/100){
			BG3VOFF = 195;
			BG0VOFF = 32;		
			BG1VOFF = 64;	
			BG2VOFF = 192;			
		} else if (get_time() == ((1306) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1307) * SECOND)/100){
			BG3VOFF = 65;		
		} else if (get_time() == ((1308) * SECOND)/100){
			BG3VOFF = 130;		
		} else if (get_time() == ((1309) * SECOND)/100){
			BG3VOFF = 260;		
		} else if (get_time() == ((1310) * SECOND)/100){
			BG3VOFF = 65;
			BG0VOFF = 0;		
			BG1VOFF = 32;	
			BG2VOFF = 160;
		} else if (get_time() == ((1315) * SECOND)/100){
			toggle_bg_displayed(3);
			load_bg_data_1(2, &BG_8_1Tiles, &BG_8_1Map);
			BG1VOFF = 0;	
		} else if (get_time() == ((1350) * SECOND)/100){
			BG0HOFF = 1;
			BG2HOFF = 1;
		} else if (get_time() == ((1352) * SECOND)/100){
			BG1HOFF = 1;
		} else if (get_time() == ((1356) * SECOND)/100){
			BG0HOFF = 2;
			BG2HOFF = 2;
		} else if (get_time() == ((1358) * SECOND)/100){
			BG1HOFF = 2;
		} else if (get_time() == ((1362) * SECOND)/100){ 
			BG0HOFF = 3;
			BG2HOFF = 3;
		} else if (get_time() == ((1364) * SECOND)/100){
			BG1HOFF = 3;
		} else if (get_time() == ((1368) * SECOND)/100){
			BG0HOFF = 4;
			BG2HOFF = 4;
		} else if (get_time() == ((1370) * SECOND)/100){
			BG1HOFF = 4;
		} else if (get_time() == ((1374) * SECOND)/100){
			BG0HOFF = 5;
			BG2HOFF = 5;
		} else if (get_time() == ((1372) * SECOND)/100){
			BG1HOFF = 5;
		} else if (get_time() == ((1376) * SECOND)/100){
			BG0HOFF = 6;
			BG2HOFF = 6;
		} else if (get_time() == ((1378) * SECOND)/100){
			BG1HOFF = 6;
		} else if (get_time() == ((1382) * SECOND)/100){
			BG0HOFF = 7;
			BG2HOFF = 7;
		} else if (get_time() == ((1384) * SECOND)/100){
			BG1HOFF = 7;
		} else if (get_time() == ((1388) * SECOND)/100){
			BG0HOFF = 8;
			BG2HOFF = 8;
		} else if (get_time() == ((1390) * SECOND)/100){
			BG1HOFF = 8;
		} else if (get_time() == ((1394) * SECOND)/100){
			BG0HOFF = 9;
			BG2HOFF = 9;
		} else if (get_time() == ((1396) * SECOND)/100){
			BG1HOFF = 9;
		} else if (get_time() == ((1400) * SECOND)/100){
			BG0HOFF = 10;
			BG2HOFF = 10;
		} else if (get_time() == ((1402) * SECOND)/100){
			BG1HOFF = 10;
		} else if (get_time() == ((1406) * SECOND)/100){
			BG0HOFF = 11;
			BG2HOFF = 11;
		} else if (get_time() == ((1408) * SECOND)/100){
			BG1HOFF = 11;
		} else if (get_time() == ((1412) * SECOND)/100){
			BG0HOFF = 12;
			BG2HOFF = 12;
		} else if (get_time() == ((1414) * SECOND)/100){
			BG1HOFF = 12;
		} else if (get_time() == ((1418) * SECOND)/100){
			BG0HOFF = 13;
			BG2HOFF = 13;
		} else if (get_time() == ((1420) * SECOND)/100){
			BG1HOFF = 13;
		} else if (get_time() == ((1424) * SECOND)/100){
			BG0HOFF = 14;
			BG2HOFF = 14;
		} else if (get_time() == ((1428) * SECOND)/100){
			BG1HOFF = 14;
		} else if (get_time() == ((1430) * SECOND)/100){
			BG0HOFF = 15;
			BG2HOFF = 15;
		} else if (get_time() == ((1434) * SECOND)/100){
			BG1HOFF = 15;
		} else if (get_time() == ((1436) * SECOND)/100){
			BG0HOFF = 16;
			BG2HOFF = 16;
		} else if (get_time() == ((1440) * SECOND)/100){
			BG1HOFF = 16;
		} else if (get_time() == ((1442) * SECOND)/100){
			BG0HOFF = 17;
			BG2HOFF = 17;
		} else if (get_time() == ((1446) * SECOND)/100){
			BG1HOFF = 17;
		} else if (get_time() == ((1448) * SECOND)/100){
			BG0HOFF = 18;
			BG2HOFF = 18;
		} else if (get_time() == ((1452) * SECOND)/100){
			BG1HOFF = 18;
		} else if (get_time() == ((1454) * SECOND)/100){
			BG0HOFF = 19;
			BG2HOFF = 19;
		} else if (get_time() == ((1458) * SECOND)/100){
			BG1HOFF = 19;
		} else if (get_time() == ((1460) * SECOND)/100){
			BG0HOFF = 20;
			BG2HOFF = 20;
		} else if (get_time() == ((1464) * SECOND)/100){
			BG1HOFF = 20;
		} else if (get_time() == ((1466) * SECOND)/100){
			BG0HOFF = 21;
			BG2HOFF = 21;
		} else if (get_time() == ((1470) * SECOND)/100){
			BG1HOFF = 21;
		} else if (get_time() == ((1472) * SECOND)/100){
			BG0HOFF = 22;
			BG2HOFF = 22;
		} else if (get_time() == ((1476) * SECOND)/100){
			BG1HOFF = 22;
		} else if (get_time() == ((1478) * SECOND)/100){
			BG0HOFF = 22;
			BG2HOFF = 22;
		} else if (get_time() == ((1482) * SECOND)/100){
			BG1HOFF = 23;
		} else if (get_time() == ((1484) * SECOND)/100){
			BG0HOFF = 24;
			BG2HOFF = 24;
		} else if (get_time() == ((1488) * SECOND)/100){
			BG1HOFF = 24;
		} else if (get_time() == ((1490) * SECOND)/100){
			BG0HOFF = 25;
			BG2HOFF = 25;
		} else if (get_time() == ((1494) * SECOND)/100){
			BG1HOFF = 25;
		} else if (get_time() == ((1496) * SECOND)/100){
			BG0HOFF = 26;
			BG2HOFF = 26;
		} else if (get_time() == ((1500) * SECOND)/100){
			BG1HOFF = 26;
		} else if (get_time() == ((1502) * SECOND)/100){
			BG0HOFF = 27;
			BG2HOFF = 27;
		} else if (get_time() == ((1506) * SECOND)/100){
			BG1HOFF = 27;
		} else if (get_time() == ((1508) * SECOND)/100){
			BG0HOFF = 28;
			BG2HOFF = 28;
		} else if (get_time() == ((1512) * SECOND)/100){
			BG1HOFF = 28;
		} else if (get_time() == ((1514) * SECOND)/100){
			BG0HOFF = 29;
			BG2HOFF = 29;
		} else if (get_time() == ((1518) * SECOND)/100){
			BG1HOFF = 29;
		} else if (get_time() == ((1520) * SECOND)/100){
			BG0HOFF = 30;
			BG2HOFF = 30;
		} else if (get_time() == ((1524) * SECOND)/100){
			BG1HOFF = 30;
		} else if (get_time() == ((1526) * SECOND)/100){
			BG0HOFF = 31;
			BG2HOFF = 31;
		} else if (get_time() == ((1530) * SECOND)/100){
			BG1HOFF = 31;
		} else if (get_time() == ((1532) * SECOND)/100){
			BG1HOFF = 32;
			BG0HOFF = 39;
			BG2HOFF = 39;
		} else if (get_time() == ((1534) * SECOND)/100){
			BG1HOFF = 40;
			BG0HOFF = 47;
			BG2HOFF = 47;
		} else if (get_time() == ((1536) * SECOND)/100){
			BG1HOFF = 48;
			BG0HOFF = 55;
			BG2HOFF = 55;
		} else if (get_time() == ((1538) * SECOND)/100){
			BG1HOFF = 56;
			BG0HOFF = 63;
			BG2HOFF = 63;
		} else if (get_time() == ((1540) * SECOND)/100){
			BG1HOFF = 64;
			BG0HOFF = 71;
			BG2HOFF = 71;
		} else if (get_time() == ((1542) * SECOND)/100){
			BG1HOFF = 72;
			BG0HOFF = 79;
			BG2HOFF = 79;
		} else if (get_time() == ((1544) * SECOND)/100){
			BG1HOFF = 80;
			BG0HOFF = 87;
			BG2HOFF = 87;
		} else if (get_time() == ((1546) * SECOND)/100){
			BG1HOFF = 88;
			BG0HOFF = 95;
			BG2HOFF = 95;
		} else if (get_time() == ((1550) * SECOND)/100){
			BG1HOFF = 96;
		} else if (get_time() == ((1552) * SECOND)/100){
			BG0HOFF = 96;
			BG2HOFF = 96;
		} else if (get_time() == ((1556) * SECOND)/100){
			BG1HOFF = 97;
		} else if (get_time() == ((1558) * SECOND)/100){
			BG0HOFF = 97;
			BG2HOFF = 97;
		} else if (get_time() == ((1562) * SECOND)/100){
			BG1HOFF = 98;
		} else if (get_time() == ((1564) * SECOND)/100){
			BG0HOFF = 98;
			BG2HOFF = 98;
		} else if (get_time() == ((1568) * SECOND)/100){
			BG1HOFF = 99;
		} else if (get_time() == ((1570) * SECOND)/100){
			BG0HOFF = 99;
			BG2HOFF = 99;
		} else if (get_time() == ((1574) * SECOND)/100){
			BG1HOFF = 100;
		} else if (get_time() == ((1576) * SECOND)/100){
			BG0HOFF = 100;
			BG2HOFF = 100;
		} else if (get_time() == ((1580) * SECOND)/100){
			BG1HOFF = 101;
		} else if (get_time() == ((1582) * SECOND)/100){
			BG0HOFF = 101;
			BG2HOFF = 101;
		} else if (get_time() == ((1586) * SECOND)/100){
			BG1HOFF = 102;
		} else if (get_time() == ((1588) * SECOND)/100){
			BG0HOFF = 102;
			BG2HOFF = 102;
		} else if (get_time() == ((1592) * SECOND)/100){
			BG1HOFF = 103;
		} else if (get_time() == ((1594) * SECOND)/100){
			BG0HOFF = 103;
			BG2HOFF = 103;
		} else if (get_time() == ((1598) * SECOND)/100){
			BG1HOFF = 104;
		} else if (get_time() == ((1600) * SECOND)/100){
			BG0HOFF = 104;
			BG2HOFF = 104;
		} else if (get_time() == ((1604) * SECOND)/100){
			BG1HOFF = 105;
		} else if (get_time() == ((1606) * SECOND)/100){
			BG0HOFF = 105;
			BG2HOFF = 105;
		} else if (get_time() == ((1610) * SECOND)/100){
			BG1HOFF = 106;
		} else if (get_time() == ((1612) * SECOND)/100){
			BG0HOFF = 106;
			BG2HOFF = 106;
		} else if (get_time() == ((1616) * SECOND)/100){
			BG1HOFF = 107;
		} else if (get_time() == ((1618) * SECOND)/100){
			BG0HOFF = 107;
			BG2HOFF = 107;
		} else if (get_time() == ((1622) * SECOND)/100){
			BG1HOFF = 108;
		} else if (get_time() == ((1624) * SECOND)/100){
			BG0HOFF = 108;
			BG2HOFF = 108;
		} else if (get_time() == ((1628) * SECOND)/100){
			BG1HOFF = 109;
		} else if (get_time() == ((1630) * SECOND)/100){
			BG0HOFF = 109;
			BG2HOFF = 109;
		} else if (get_time() == ((1634) * SECOND)/100){
			BG1HOFF = 110;
		} else if (get_time() == ((1636) * SECOND)/100){
			BG0HOFF = 110;
			BG2HOFF = 110;
		} else if (get_time() == ((1640) * SECOND)/100){
			BG1HOFF = 111;
		} else if (get_time() == ((1642) * SECOND)/100){
			BG0HOFF = 111;
			BG2HOFF = 111;
		} else if (get_time() == ((1646) * SECOND)/100){
			BG1HOFF = 112;
		} else if (get_time() == ((1648) * SECOND)/100){
			BG0HOFF = 112;
			BG2HOFF = 112;
		} else if (get_time() == ((1652) * SECOND)/100){
			BG1HOFF = 113;
		} else if (get_time() == ((1654) * SECOND)/100){
			BG0HOFF = 113;
			BG2HOFF = 113;
		} else if (get_time() == ((1658) * SECOND)/100){
			BG1HOFF = 114;
		} else if (get_time() == ((1660) * SECOND)/100){
			BG0HOFF = 114;
			BG2HOFF = 114;
		} else if (get_time() == ((1664) * SECOND)/100){
			BG1HOFF = 115;
		} else if (get_time() == ((1666) * SECOND)/100){
			BG0HOFF = 115;
			BG2HOFF = 115;
		} else if (get_time() == ((1670) * SECOND)/100){
			BG1HOFF = 116;
		} else if (get_time() == ((1672) * SECOND)/100){
			BG0HOFF = 116;
			BG2HOFF = 116;
		} else if (get_time() == ((1676) * SECOND)/100){
			BG1HOFF = 117;
		} else if (get_time() == ((1678) * SECOND)/100){
			BG0HOFF = 117;
			BG2HOFF = 117;
		} else if (get_time() == ((1682) * SECOND)/100){
			BG1HOFF = 118;
		} else if (get_time() == ((1684) * SECOND)/100){
			BG0HOFF = 118;
			BG2HOFF = 118;
		} else if (get_time() == ((1688) * SECOND)/100){
			BG1HOFF = 119;
		} else if (get_time() == ((1690) * SECOND)/100){
			BG0HOFF = 119;
			BG2HOFF = 119;
		} else if (get_time() == ((1694) * SECOND)/100){
			BG1HOFF = 120;
		} else if (get_time() == ((1696) * SECOND)/100){
			BG0HOFF = 120;
			BG2HOFF = 120;
		} else if (get_time() == ((1700) * SECOND)/100){
			BG1HOFF = 121;
		} else if (get_time() == ((1702) * SECOND)/100){
			BG0HOFF = 121;
			BG2HOFF = 121;
		} else if (get_time() == ((1706) * SECOND)/100){
			BG1HOFF = 122;
		} else if (get_time() == ((1708) * SECOND)/100){
			BG0HOFF = 122;
			BG2HOFF = 122;
		} else if (get_time() == ((1712) * SECOND)/100){
			BG1HOFF = 123;
		} else if (get_time() == ((1714) * SECOND)/100){
			BG0HOFF = 123;
			BG2HOFF = 123;
		} else if (get_time() == ((1718) * SECOND)/100){
			BG1HOFF = 124;
		} else if (get_time() == ((1720) * SECOND)/100){
			BG0HOFF = 124;
			BG2HOFF = 124;
		} else if (get_time() == ((1724) * SECOND)/100){
			BG1HOFF = 125;
		} else if (get_time() == ((1726) * SECOND)/100){
			BG0HOFF = 125;
			BG2HOFF = 125;
		} else if (get_time() == ((1730) * SECOND)/100){
			BG1HOFF = 126;
		} else if (get_time() == ((1732) * SECOND)/100){
			BG0HOFF = 126;
			BG2HOFF = 126;
		} else if (get_time() == ((1736) * SECOND)/100){
			BG1HOFF = 127;
		} else if (get_time() == ((1800) * SECOND)/100){
			fadescreen();
		} else if (get_time() == ((1850) * SECOND)/100){
			clear_bgs();
			DISPCNT = 0x1FC0;
			set_bg_config_2();
			DISPCNT = 0x1F40;
			restart_bgs();
		    load_sprite_pal(&OBJ_3Pal, 3, false);
		    load_sprite_pal(&OBJ_5Pal, 4, false);
			load_bg_pal(0, &BG_Pal_1, false);
			load_bg_data_2(1, &BG_10Tiles, &BG_10Map);
		} else if (get_time() == ((1970) * SECOND)/100){
			load_bg_data_2(2, &BG_11Tiles, &BG_11Map);
		} else if (get_time() == ((2004) * SECOND)/100){
			load_bg_data_2(3, &BG_12Tiles, &BG_12Map);
		} else if (get_time() == ((2042) * SECOND)/100){
			load_bg_data_2(1, &BG_13Tiles, &BG_13Map);
		} else if (get_time() == ((2060) * SECOND)/100){
			load_bg_data_2(0, &BG_14Tiles, &BG_14Map);
		} else if (get_time() == 21 * SECOND){
			fadescreen();
		} else if (get_time() == ((2150) * SECOND)/100){
			load_bg_data_2(1, &BG_15Tiles, &BG_15Map);
			load_bg_data_2(2, &BG_16Tiles, &BG_16Map);
			load_bg_data_2(3, &BG_17Tiles, &BG_17Map);	
			DISPCNT = 0x1E40;
		} else if (get_time() == ((2152) * SECOND)/100){
			unfadescreen();
		} else if (get_time() == ((2200) * SECOND)/100){
			BG1HOFF = 40;
		} else if (get_time() == ((2203) * SECOND)/100){
			BG1HOFF = 72;
		} else if (get_time() == ((2206) * SECOND)/100){
			BG1HOFF = 104;
		} else if (get_time() == ((2209) * SECOND)/100){
			BG1HOFF = 140;
		} else if (get_time() == ((2212) * SECOND)/100){
			BG1HOFF = 177;
		} else if (get_time() == ((2200) * SECOND)/100){
			BG2HOFF = 484;
		} else if (get_time() == ((2220) * SECOND)/100){
			BG2HOFF = 452;
		} else if (get_time() == ((2223) * SECOND)/100){
			BG2HOFF = 420;
		} else if (get_time() == ((2226) * SECOND)/100){
			BG2HOFF = 384;
		} else if (get_time() == ((2229) * SECOND)/100){
			BG2HOFF = 347;
		} else if (get_time() == ((2400) * SECOND)/100){
			BG1HOFF = 160;
			load_sprite(&hide_oam, &OBJ_3Tiles, Unown_1, 3, 1, SPRITE_NO_ANIMATION);
		} else if (get_time() == ((2402) * SECOND)/100){
			BG1HOFF = 144;
			move_sprite(Unown_1, 32, 59);
		} else if (get_time() == ((2404) * SECOND)/100){
			BG1HOFF = 128;
		} else if (get_time() == ((2406) * SECOND)/100){
			BG1HOFF = 112;
			move_sprite(Unown_1, 32, 0);
		} else if (get_time() == ((2408) * SECOND)/100){
			BG1HOFF = 96;
		} else if (get_time() == ((2410) * SECOND)/100){
			BG1HOFF = 80;
			move_sprite(Unown_1, 32, 0);
		} else if (get_time() == ((2412) * SECOND)/100){
			BG1HOFF = 64;
		} else if (get_time() == ((2414) * SECOND)/100){
			BG1HOFF = 48;
			move_sprite(Unown_1, 32, 0);
		} else if (get_time() == ((2416) * SECOND)/100){
			BG1HOFF = 32;
		} else if (get_time() == ((2418) * SECOND)/100){
			BG1HOFF = 16;
			move_sprite(Unown_1, 32, 0);
		} else if (get_time() == ((2420) * SECOND)/100){
			BG1HOFF = 0;
		} else if (get_time() == ((2422) * SECOND)/100){
			move_sprite(Unown_1, 32, 0);
			load_sprite(&hide_oam, &OBJ_3Tiles, Unown_2, 3, 1, SPRITE_NO_ANIMATION);
		} else if (get_time() == ((2424) * SECOND)/100){
			BG2HOFF = 364;
			move_sprite(Unown_1, 32, 0);
			move_sprite(Unown_2, 272, 165);
		} else if (get_time() == ((2426) * SECOND)/100){
			delete_sprite(Unown_1);
			BG2HOFF = 380;
		} else if (get_time() == ((2428) * SECOND)/100){
			BG2HOFF = 396;
			move_sprite(Unown_2, -32, 0);
		} else if (get_time() == ((2430) * SECOND)/100){
			BG2HOFF = 412;
		} else if (get_time() == ((2432) * SECOND)/100){
			BG2HOFF = 428;
			move_sprite(Unown_2, -32, 0);
		} else if (get_time() == ((2434) * SECOND)/100){
			BG2HOFF = 444;
		} else if (get_time() == ((2436) * SECOND)/100){
			BG2HOFF = 460;
			move_sprite(Unown_2, -32, 0);
		} else if (get_time() == ((2438) * SECOND)/100){
			BG2HOFF = 476;
		} else if (get_time() == ((2440) * SECOND)/100){
			BG2HOFF = 492;
			move_sprite(Unown_2, -32, 0);
		} else if (get_time() == ((2442) * SECOND)/100){
			BG2HOFF = 508;
		} else if (get_time() == ((2444) * SECOND)/100){
			BG2HOFF = 524;
			move_sprite(Unown_2, -32, 0);
		} else if (get_time() == ((2446) * SECOND)/100){
			move_sprite(Unown_2, -32, 0);			
		} else if (get_time() == ((2448) * SECOND)/100){
			move_sprite(Unown_2, -32, 0);
		} else if (get_time() == ((2450) * SECOND)/100){
			move_sprite(Unown_2, -32, 0);			
		} else if (get_time() == ((2452) * SECOND)/100){
			move_sprite(Unown_2, -32, 0);
		} else if (get_time() == ((2500) * SECOND)/100){
			fadescreen();
		} else if (get_time() == ((2530) * SECOND)/100){
			set_var(0,1);
		}	
	}		
	if (get_time() == (797 * SECOND)/100){
		BG2PA = 0x2000;
		BG2PD = 0x2000;
		BG2X_L = 0x4000;
		BG2X_H = 0x0FF1;
		BG2Y_L = 0x4000;
		BG2Y_H = 0x0FF8;
	} else if (get_time() == (803 * SECOND)/100){	
		BG2PA = 0x1400;
		BG2PD = 0x1400;
		BG2X_L = 0xE000;
		BG2X_H = 0x0FF6;
		BG2Y_L = 0xF800;
		BG2Y_H = 0x0FFA;
	} else if (get_time() == (807 * SECOND)/100){   
		BG2PA = 0x0C00;
		BG2PD = 0x0C00;
		BG2X_L = 0xA000;
		BG2X_H = 0x0FFA;
		BG2Y_L = 0x1400;
		BG2Y_H = 0x0FFD;		
	} else if (get_time() == (809 * SECOND)/100){	
		BG2PA = 0x0800;
		BG2PD = 0x0800;
		BG2X_L = 0x8200;
		BG2X_H = 0x0FFC;
		BG2Y_L = 0x1600;
		BG2Y_H = 0x0FFE;		
		load_bg_data(2, &BG_4_2Tiles, &BG_4_2Map);
	} else if (get_time() == (821 * SECOND)/100){	
		BG2PA = 0x0600;
		BG2PD = 0x0600;
		BG2X_L = 0x7200;
		BG2X_H = 0x0FFD;
		BG2Y_L = 0x8000;
		BG2Y_H = 0x0FFE;
		load_bg_data(2, &BG_4_3Tiles, &BG_4_3Map);
	} else if (get_time() == (827 * SECOND)/100){ 
		BG2PA = 0x05F0;
		BG2PD = 0x05F0;
		BG2X_L = 0x7E00;
		BG2X_H = 0x0FFD;
		BG2Y_L = 0x8000;
		BG2Y_H = 0x0FFE;		
	} else if (get_time() == (833 * SECOND)/100){
		BG2PA = 0x0480;
		BG2PD = 0x0480;
		BG2X_L = 0x2800;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0xF000;
		BG2Y_H = 0x0FFE;		
		load_bg_data(2, &BG_4_4Tiles, &BG_4_4Map);
	} else if (get_time() == (837 * SECOND)/100){
		BG2PA = 0x0480;
		BG2PD = 0x03C0;
		BG2X_L = 0x2800;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x1D00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (845 * SECOND)/100){	
		load_bg_data(2, &BG_4_5Tiles, &BG_4_5Map);
	} else if (get_time() == (849 * SECOND)/100){
		BG2PA = 0x0410;
		BG2PD = 0x03C0;
		BG2X_L = 0x5A80;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x1D00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (853 * SECOND)/100){
		BG2PA = 0x0408;
		BG2PD = 0x03A0;
		BG2X_L = 0x5E40;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x1F00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (857 * SECOND)/100){	
		BG2PA = 0x0408;
		BG2PD = 0x03C0;
		BG2X_L = 0x5E40;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x1200;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_6Tiles, &BG_4_6Map);
	} else if (get_time() == (859 * SECOND)/100){	
		BG2PA = 0x038C;
		BG2PD = 0x03A0;
		BG2X_L = 0x9680;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x1A00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (863 * SECOND)/100){	
		BG2PA = 0x035C;
		BG2PD = 0x0360;
		BG2X_L = 0xAE8C;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x2500;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (865 * SECOND)/100){	
		BG2PA = 0x035C;
		BG2PD = 0x0340;
		BG2X_L = 0xAE8C;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x3000;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (869 * SECOND)/100){	
		BG2PA = 0x037C;
		BG2PD = 0x0340;
		BG2X_L = 0xA0D8;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x3000;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_1Tiles, &BG_4_1Map);
	} else if (get_time() == (871 * SECOND)/100){	
		BG2PA = 0x0360;
		BG2PD = 0x0320;
		BG2X_L = 0xACA0;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x3C00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (875 * SECOND)/100){	
		BG2PA = 0x02EC;
		BG2PD = 0x0320;
		BG2X_L = 0xE2B0;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x3440;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (877 * SECOND)/100){	
		BG2PA = 0x02F4;
		BG2PD = 0x02F8;
		BG2X_L = 0xDEF0;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x4280;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (881 * SECOND)/100){	
		BG2PA = 0x02B8;
		BG2PD = 0x02F8;
		BG2X_L = 0xFB20;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x3800;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_2Tiles, &BG_4_2Map);
	} else if (get_time() == (883 * SECOND)/100){	
		BG2PA = 0x02B8;
		BG2PD = 0x02F8;
		BG2X_L = 0xFB18;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x3200;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (887 * SECOND)/100){	
		BG2PA = 0x02B8;
		BG2PD = 0x02F8;
		BG2X_L = 0xFB20;
		BG2X_H = 0x0FFE;
		BG2Y_L = 0x3400;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (889 * SECOND)/100){	
		BG2PA = 0x02A0;
		BG2PD = 0x02C0;
		BG2X_L = 0x0640;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x4200;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (893 * SECOND)/100){	
		BG2PA = 0x0260;
		BG2PD = 0x0270;
		BG2X_L = 0x2430;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x5600;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_3Tiles, &BG_4_3Map);
	} else if (get_time() == (895 * SECOND)/100){	
		BG2PA = 0x0260;
		BG2PD = 0x0270;
		BG2X_L = 0x2430;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x5500;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (899 * SECOND)/100){	
		BG2PA = 0x024C;
		BG2PD = 0x0270;
		BG2X_L = 0x2D80;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x5000;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (905 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x0220;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6F20;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_4Tiles, &BG_4_4Map);
	} else if (get_time() == (907 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x0220;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6E00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (911 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x0218;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6C00;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (913 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x0214;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6C80;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (917 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x0214;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6E00;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_5Tiles, &BG_4_5Map);
	} else if (get_time() == (921 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x020E;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6E00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (925 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x020E;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6C00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (927 * SECOND)/100){	
		BG2PA = 0x0230;
		BG2PD = 0x020E;
		BG2X_L = 0x3A90;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6A00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (929 * SECOND)/100){	
		BG2PA = 0x01F0;
		BG2PD = 0x0200;
		BG2X_L = 0x5870;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x6E00;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_6Tiles, &BG_4_6Map);
	} else if (get_time() == (931 * SECOND)/100){	
		BG2PA = 0x01F0;
		BG2PD = 0x0200;
		BG2X_L = 0x5870;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x7000;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (935 * SECOND)/100){	
		BG2PA = 0x01E0;
		BG2PD = 0x01F8;
		BG2X_L = 0x5FE0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x7800;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (937 * SECOND)/100){	
		BG2PA = 0x01E0;
		BG2PD = 0x01F4;
		BG2X_L = 0x5FE0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x7FE0;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (941 * SECOND)/100){	
		BG2PA = 0x01E0;
		BG2PD = 0x01E0;
		BG2X_L = 0x5FE0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x8800;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_1Tiles, &BG_4_1Map);
	} else if (get_time() == (943 * SECOND)/100){	
		BG2PA = 0x01E0;
		BG2PD = 0x01E0;
		BG2X_L = 0x5FE0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x8C00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (947 * SECOND)/100){	
		BG2PA = 0x01E0;
		BG2PD = 0x01C0;
		BG2X_L = 0x5FE0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x9800;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (949 * SECOND)/100){	
		BG2PA = 0x01E0;
		BG2PD = 0x01B4;
		BG2X_L = 0x5FE0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x9C00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (953 * SECOND)/100){	
		BG2PA = 0x01B2;
		BG2PD = 0x01B4;
		BG2X_L = 0x7560;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x9C00;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_2Tiles, &BG_4_2Map);
	} else if (get_time() == (955 * SECOND)/100){	
		BG2PA = 0x01B0;
		BG2PD = 0x01B0;
		BG2X_L = 0x7640;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x9E00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (959 * SECOND)/100){	
		BG2PA = 0x01B0;
		BG2PD = 0x01B0;
		BG2X_L = 0x7650;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xA000;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (961 * SECOND)/100){	
		BG2PA = 0x01B0;
		BG2PD = 0x01B0;
		BG2X_L = 0x7650;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xA200;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (965 * SECOND)/100){	
		BG2PA = 0x01A8;
		BG2PD = 0x01B0;
		BG2X_L = 0x7A00;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x9A00;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_3Tiles, &BG_4_3Map);
	} else if (get_time() == (967 * SECOND)/100){	
		BG2PA = 0x017C;
		BG2PD = 0x0184;
		BG2X_L = 0x8E9C;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xAE00;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (971 * SECOND)/100){	
		BG2PA = 0x017C;
		BG2PD = 0x017E;
		BG2X_L = 0x8E9C;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xB200;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (973 * SECOND)/100){	
		BG2PA = 0x0170;
		BG2PD = 0x0174;
		BG2X_L = 0x9430;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xB700;
		BG2Y_H = 0x0FFF;		
	} else if (get_time() == (977 * SECOND)/100){	
		BG2PA = 0x0160;
		BG2PD = 0x0140;
		BG2X_L = 0x9B00;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xD200;
		BG2Y_H = 0x0FFF;		
		load_bg_data(2, &BG_4_4Tiles, &BG_4_4Map);
	} else if (get_time() == (981 * SECOND)/100){	
		BG2PA = 0x0160;
		BG2PD = 0x0140;
		BG2X_L = 0x9B00;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xD400;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (983 * SECOND)/100){	
		BG2PA = 0x013C;
		BG2PD = 0x0120;
		BG2X_L = 0xAC78;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xDA00;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (987 * SECOND)/100){	
		BG2PA = 0x013C;
		BG2PD = 0x0110;
		BG2X_L = 0xAC78;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xE400;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (989 * SECOND)/100){	
		BG2PA = 0x0110;
		BG2PD = 0x0110;
		BG2X_L = 0xC100;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xEA00;
		BG2Y_H = 0x0FFF;
		load_bg_data(2, &BG_4_5Tiles, &BG_4_5Map);
	} else if (get_time() == (993 * SECOND)/100){	
		BG2PA = 0x0108;
		BG2PD = 0x0110;
		BG2X_L = 0xC500;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xEE00;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (995 * SECOND)/100){	
		BG2PA = 0x0108;
		BG2PD = 0x0108;
		BG2X_L = 0xC500;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xF200;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (999 * SECOND)/100){	
		BG2PA = 0x0100;
		BG2PD = 0x0100;
		BG2X_L = 0xC800;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xF600;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (1001 * SECOND)/100){	
		BG2PA = 0x00F0;
		BG2PD = 0x0100;
		BG2X_L = 0xCFF0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xF900;
		BG2Y_H = 0x0FFF;
		load_bg_data(2, &BG_4_6Tiles, &BG_4_6Map);
	} else if (get_time() == (1005 * SECOND)/100){	
		BG2PA = 0x00F0;
		BG2PD = 0x00F0;
		BG2X_L = 0xCFF0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0xFE00;
		BG2Y_H = 0x0FFF;
	} else if (get_time() == (1007 * SECOND)/100){	
		BG2PA = 0x00E0;
		BG2PD = 0x00F0;
		BG2X_L = 0xD7B0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x0100;
		BG2Y_H = 0x0000;
	} else if (get_time() == (1009 * SECOND)/100){	
		BG2PA = 0x00E0;
		BG2PD = 0x00E0;
		BG2X_L = 0xD7B0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x0D00;
		BG2Y_H = 0x0000;
	} else if (get_time() == (1013 * SECOND)/100){	
		BG2PA = 0x00E0;
		BG2PD = 0x00E0;
		BG2X_L = 0xD7B0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x0D00;
		BG2Y_H = 0x0000;
		load_bg_data(2, &BG_4_1Tiles, &BG_4_1Map);
	} else if (get_time() == (1015 * SECOND)/100){	
		BG2PA = 0x00D0;
		BG2PD = 0x00E0;
		BG2X_L = 0xDEB0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x0E00;
		BG2Y_H = 0x0000;
	} else if (get_time() == (1019 * SECOND)/100){	
		BG2PA = 0x00D0;
		BG2PD = 0x00D0;
		BG2X_L = 0xDEB0;
		BG2X_H = 0x0FFF;
		BG2Y_L = 0x1D00;
		BG2Y_H = 0x0000;
	}
	if (key_down(KEY_A | KEY_B | KEY_START) || get_var(0) == 1) {
		return true;
	}
	inc_timer();
	return false;
}

	