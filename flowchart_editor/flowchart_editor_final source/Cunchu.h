#include "BasicShape.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Rhombus.h"
#include "Quadrangle.h"

typedef struct Node			//无用处，已经废弃
 {	
	CBasicShape* pr;
	struct Node* next;
 }stor_node;