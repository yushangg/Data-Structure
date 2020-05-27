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
int calSub(float opand1, char op, float opand2, float &result) {
	if (op == '+') result = opand1 + opand2;
	if (op == '-') result = opand1 - opand2;
	if (op == '*') result = opand1 * opand2;
	if (op == '/') {
		if (fabs(opand2) < MIN) {
			return 0;
		}
		else {
			result = opand1 / opand2;
		}
	}
	return 1;
}

int calStackTopTwo(float s1[], int &top1, char s2[], int &top2) {
	float opand1, opand2, result;
	char op;
	int flag;
	opand2 = s1[top--];
	opand1 = s1[top--];
	op = s2[top2--];
	flag = calSub(opand1, op, opand2, result);
	if (flag == 0) {
		std::cout << "ERROR" <<endl;
	}
	s1[++top1] = result;
	return flag;
}

float calInfix(char exp[]) {
	float s1[maxSize];
	char s2[maxSize];
	int top1 = -1, top = -1;
	while (exp[i] != '\0') {
		if ('0' <= exp[i] && exp[i] <= 9) {
			s1[++top1] = exp[i] - '0';
			i++;
		}
		else if (exp[i] == '(') {
			s2[++top2] = '(';
			++i;
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			if (top2 == -1 || s2[top2] == '(' || getPriority(exp[i]) > getPriority(s2[top2])) {
				s2[++top2] = exp[i];
				i++;
			}
			else {
				int flag = calStackTopTwo(s1, top1, s2, top2);
				if (flag == 0) return 0;
			} 
		}
		else if (exp[i] == ')') {
			while (s2[top2] != '(') {
				int flag = calStackTopTwo(s1, top1, s2, top2);
				if (flag == 0) return 0;
			}
			top2--;
			i++;
		}
	}
	while (top2 != -1) {
		int flag = calStackTopTwo(s1, top1, s2, top2);
		if (flag == 0) return 0;
	}
	return s1[top1];
}


//calculate the result of postfix  (only number and + - * /)
float claPostFix(char exp[]) {
	float s[maxSize];
	int top = -1;
	int i = 0;
	for (int i = 0; exp[i] != '\0'; i++) {
		if ('0' <= exp[i] && exp[i] <= '9') {
			s[++top] = exp[i] - '0';
		}
		else {
			float opand1, opand2, result;
			char op;
			int flag;
			opand2 = s[top--];
			opand1 = s[top--];
			op = exp[i];
			flag = calSub(opand1, op, opand2, result);
			if (flag == 0) {
				std::cout << "error" << std::endl;
				return 0;
			}
			s[++top] = result;
		}
	}
	return s[top];
}


//calculate the result of prefix (from right to  left)
float calPreFix(char exp[], int len) {
	float s[maxSize];
	int top = -1;
	for (int i = len - 1; i >= 0; i--) {
		if ('0' <= exp[i] && exp[i] >= '9') {
			s[++top] = exp[i] - '0';
		}
		else {
			float opand1, opand2, result;
			char op;
			int flag;
			opand1 = s[top--];
			opand2 = s[top--];
			op = exp[i];
			flag = calSub(opand1, op, opand2, result);
			if (flag == 0) {
				std::cout << "error" << std::endl;
				return 0;
			}
			s[++top] = result;
		}
	}
	return s[top];
}

