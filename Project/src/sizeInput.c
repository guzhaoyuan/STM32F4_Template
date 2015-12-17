#include "sizeInput.h"

void Input_Init(void){

}

void Input_Display(SIZE *size){//TODO:显示当前路径的步骤数

}   

void Calculate_Route(SIZE *size){
	int baseX = 10;
	int baseY = 10;
	int speed = 10;
	float x = size->x;
	float y = size->y;
	float z = size->z;
	size->route = (NODE*) malloc(12*sizeof(NODE));
	size->route[0] = (NODE){	baseX ,			baseY , 				speed};
	size->route[1] = (NODE){	baseX+z ,		baseY+z , 			speed};
	size->route[2] = (NODE){	baseX ,			baseY+z , 			speed};
	size->route[3] = (NODE){	baseX ,			baseY+x+z , 		speed};
	size->route[4] = (NODE){	baseX+z ,		baseY+x+z , 		speed};
	size->route[5] = (NODE){	baseX+z ,		baseY+x+z+x+z , speed};
	size->route[6] = (NODE){	baseX+y+z,	baseY+x+z+x+z , speed};
	size->route[7] = (NODE){	baseX+y+z,	baseY+x+z , 		speed};
	size->route[8] = (NODE){	baseX+y+z+z,baseY+x+z , 		speed};
	size->route[9] = (NODE){	baseX+y+z+z,baseY+z , 			speed};
	size->route[10] = (NODE){	baseX+y+z,	baseY+z , 			speed};
	size->route[11] = (NODE){	baseX+y+z,	baseY , 				speed};
	int i ;
	for( i = 0 ; i < 12 ; i++){
		
	}
	
}

void Auto_Cmd(CMD *cmd, SIZE *size){
	Calculate_Route(&size);
}