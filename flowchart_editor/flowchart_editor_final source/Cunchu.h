#include "BasicShape.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Rhombus.h"
#include "Quadrangle.h"

typedef struct Node			//���ô����Ѿ�����
 {	
	CBasicShape* pr;
	struct Node* next;
 }stor_node;