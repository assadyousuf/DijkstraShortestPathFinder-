#include "util.h"
//=============================================================================

int nextCommand(int *i, int *v, int *f) {
	char c;
	while(1){
		scanf("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n'){
			continue;
		}
		if (c == 'W'|| c== 'w'){
			break;
		}
        if (c == 'E'|| c== 'e'){
            break;
        }
        if (c == 'I'|| c== 'i'){
            break;
        }
        if (c == 'C'|| c== 'c'){ // take in i,v,and f letters if C is inputted by user
            scanf("%d", i);
            scanf("%d", v);
            scanf("%d", f);
            break;
        }
        
		printf("Invalid Command\n");
	}
	return c;
}
