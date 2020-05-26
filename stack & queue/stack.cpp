// first in last out
/*
Catalan number : n numbers are pushed in some order, and they can be pushen out at any time ,the number of different push list is Cn
Cn = (2 * n)! / [(n + 1)! n!]
*/ 

/*
expression conversion
prefix / infix / postfix
*/

// convert from infix to postfix
//result is stored in the stack s2, and we can know the pointer is top2
void infixToPostFix(char infix[], char s2[], int &top2) {
	//auxiliary stack
	char s1[maxSize];
	int top1 = -1;
	int i = 0;
	while (infix[i] != '\0') {
		if ('0' <= infix[i] && infix[i] <= '9') {
			s2[++top2] = infix[i];
			i++;
		}
		else if (infix[i] == '(') {
			s1[++top1] = '(';
			i++;
		}
		else if (infix == '+' || infix == '-' || infix == '*' || infix == '/') {
			if (top1 = -1 || s1[top1] == '(' || getPriority(infix[i]) > getPriority(s1[top1])) {
				s1[++top1] = infix[i++];
				//i++;
			}
			else {
				s2[++top2] = s1[top1--];
			}		
		}
		else if (infix[i] == ')') {
			while (s1[top1] != ')') {
				s2[++top2] = s1[top1--];
			}
			top1--; // remove '('
			i++; // remove ')'
		}
	}
	while (top1 != -1) {
		s2[++top2] = s1[top1--];
	}
}


//convert from infix to prefix
void infixToPreFix(char infix[], int len, char s2[], int &top2) {
	//auxiliary stack
	char s1[maxSize];
	int top1 = -1;
	int i = len - 1; // from right to left
	while (i >= 0) {
		if ('0' <= infix[i] && infix[i] >= '9') {
			s2[++top2] = infix[i--];
		}
		else if (infix[i] == '(') {
			s1[++top1] = '(';
			i--;
		}
		else if (infix[i] == '+' && infix[i] == '-' && infix[i] == '*' && infix[i] == '/') {
			if (top1 == -1 || s1[top1] == ')' || getPriority(infix[i]) >= getPriority(s1[top1])) {
				s1[++top1] == infix[i--];
			}
			else {
				s2[++top2] = s1[top--];
			}
		}
		else if (infix[i] == '(') {
			while (s1[top1] != ')') {
				s2[++top2] = s1[top--];
			}
			top1--; //remove ')' in s1
			i--; // remove '(' in infix
		}
	}
	while (top1 != -1) {
		s2[++top2] = s1[top--]; // transfor left character from s1 to s2
	}
}


//get priority of symbol; only + - / *
int getPriority(char op) {
	if (op == '+' || op == '-') {
		return 0;
	}
	else {
		return 1;
	}
}


//calculate the result of infix expression
