#include <bits/stdc++.h> 
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std; 

bool matcher4(string expr){
	stack<char> s; 
	char x; 
	     
    for (int i = 0; i < expr.length(); i++){ 
		if (expr[i] == '<'){
			s.push(expr[i]); 
			continue;
		}
		if (expr[i] == '>'){
			if (s.empty())
				return false;
				s.pop(); 
		}
    } 
    return (s.empty()); 
}
bool matcher3(string expr){
	stack<char> s; 
	char x; 
	     
    for (int i = 0; i < expr.length(); i++){ 
		if (expr[i] == '{'){
			s.push(expr[i]); 
			continue;
		}
		if (expr[i] == '}'){
			if (s.empty())
				return false;
				s.pop(); 
		}
    } 
    return (s.empty()); 
}
bool matcher2(string expr){
	stack<char> s; 
	char x; 
	     
    for (int i = 0; i < expr.length(); i++){ 
		if (expr[i] == '['){
			s.push(expr[i]); 
			continue;
		}
		if (expr[i] == ']'){
			if (s.empty())
				return false;
				s.pop(); 
		}
    } 
    return (s.empty()); 
}
bool matcher1(string expr){
	stack<char> s; 
	char x; 
	     
    for (int i = 0; i < expr.length(); i++){ 
		if (expr[i] == '('){
			s.push(expr[i]); 
			continue;
		}
		if (expr[i] == ')'){
			if (s.empty())
				return false;
				s.pop(); 
		}
    } 
    return (s.empty()); 
} 
bool matcher(string expr) 
{   
    stack<char> s; 
    char x; 
   
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{' || expr[i] == '<')  
        { 
            s.push(expr[i]); 
            continue; 
        } 
  
        switch (expr[i]) { 
        case ')': 
              
            x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[' || x == '<') 
                return false; 
            break; 
  
        case '}': 
  
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[' || x == '<') 
                return false; 
            break; 
  
        case ']': 
  
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{' || x == '<') 
                return false; 
            break;
            
        case '>': 
  
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{' || x == '[') 
                return false; 
            break; 
             
        default:
			break;
        } 
    } 
  
    return (s.empty()); 
} 
  
int main() { 
	cout << "Matching Brackets: Ngan Hoang\n";
    string line;
    int a;
    int ca;
    getline(cin, line);
    size_t found = line.find('#'); 
    
    if (found != string::npos ){
		 for (int i = 0; i < line.length(); i++){ 
			 	switch (line[i]) { 
					case '(': ca = 1; break;
					case '[': ca = 2; break;
					case '{': ca = 3; break;
					case '<': ca = 4; break;
				}
			}
			
		scanf("%d", &a);
		getline(cin, line);
		
		for (int count = 0; count < a; count++){
			getline(cin, line);
			
			switch (ca){
				case 1:
					if (matcher1(line))
						cout << "1 "; 
					else
						cout << "0 ";
					break;	
				case 2:
					if (matcher2(line))
						cout << "1 "; 
					else
						cout << "0 ";
					break;	
				case 3:
					if (matcher3(line))
						cout << "1 "; 
					else
						cout << "0 ";
					break;	
				case 4:
					if (matcher4(line))
						cout << "1 "; 
					else
						cout << "0 ";
					break;	
			}
	}
}	
	else{
		a = stoi(line);
 
		for (int count = 0; count < a; count++){
			getline(cin, line);
	
			if (matcher(line))
				cout << "1 "; 
			else
				cout << "0 ";	
	}
}
		
   cout << endl;

    return 0; 
}
