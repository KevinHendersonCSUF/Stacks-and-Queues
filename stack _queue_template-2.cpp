// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Stacks-and-Queues.git

#include<iostream>
#include<vector>

// Add class Stack here
class Stack {
public:
void validPara(std::string par) {
    std::vector<char> stack;
    for(int i = 0; i < par.length(); i++) {
        if(par[i] == '(' || par[i] == '{' || par[i] == '[' ) {
        stack.push_back(par[i]);
        }
         for(int r = stack.size(); r > 0; r--) {
         if(par[i] == ')' && stack[r] == '(') {
                stack.pop_back();
         }
         if(par[i] == '}' && stack[r] == '{') {
                stack.pop_back();

         }
         if(par[i] == ']' && stack[r] == '[') {
                stack.pop_back();
         }
         }
    //     for(int j = 0; j < stack.size(); j++) {
    //     std::cout << stack[j] << " ";
    // }
    // std::cout << std::endl; //TO VISUALIZE THE STACK
    }
    
    // for(int j = 0; j < stack.size(); j++) {
    //     std::cout << stack[j] << " ";
    // }
    // std::cout << std::endl; //TO VISUALIZE THE STACK
    if (stack.size() == 0) {
        std::cout << "Valid" << std::endl;
    }
        if (stack.size() != 0) {
        std::cout << "invalid" << std::endl;
    }
}

int indexError(std::string par) {
    std::vector<char> stack;
    int par_index = 0;
    for(int i = 0; i < par.length(); i++) {
        if(par[i] == '(' || par[i] == '{' || par[i] == '[' ) {
        stack.push_back(par[i]);
        }
         for(int r = stack.size(); r > 0; r--) {
         if(par[i] == ')' && stack[r] == '(') {
                stack.pop_back();
         }
         if(par[i] == '}' && stack[r] == '{') {
                stack.pop_back();

         }
         if(par[i] == ']' && stack[r] == '[') {
                stack.pop_back();
         }
         }
         par_index++;
    }
    
    
     for(int j = 0; j < stack.size(); j++) {
        std::cout << stack[j] << " ";
    }
    std::cout << std::endl; //TO VISUALIZE THE STACK
    
    if (stack.size() == 0) {
        return 1;
    }
    return par_index;
} // NO WHERE NEAR DONE!

void minPara() {

}

int scorePara() {

return 0;
}

};

// Add class Queue here
class Queue {
public:
void enqueue(std::string message) {

}
 void processMsg() {

 }
};
// Remove comments before testing and do not change anything in main function
int main(){
Stack s1;
// s1.validPara("(([]))");
// s1.minPara("(([]))");
// s1.scorePara("(([]))");
// s1.validPara("(([])");
std::cout<<s1.indexError("(([))")<<std::endl;
// s1.minPara("(([])");
// s1.validPara("(([{}))");
std::cout<<s1.indexError("(([[}])")<<std::endl;
// s1.minPara("(([{}))");
// s1.scorePara("(([{}))");
std::cout<<s1.indexError("({}[]()[)")<<std::endl;
// s1.validPara("(([))");
// s1.minPara("(([))");
// std::cout<<s1.indexError("[({)]")<<std::endl;
// s1.validPara("(([{[{({})}]}]))");
// s1.minPara("(([{[{({})}]}]))");
// s1.scorePara("(([{[{({})}]}]))");
// s1.validPara("(([[{[{({})}]))");
// s1.validPara("(([[{[{({})}]}])]))");
// s1.scorePara("(([[{[{({})}]}])]))");
// std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
// s1.validPara("(())");
// s1.validPara("(())");
// s1.validPara("void function(){}");
// s1.scorePara("void function(){}");
// s1.validPara("void function(");
// s1.minPara("void function(");
// s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
// s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
// s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
// s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
// s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
// std::cout<<s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;")<<std::endl;
// Queue q1;
// q1.enqueue("This is a secure message.");
// q1.processMsg();
// q1.enqueue("The product I received is damaged. What should I do?");
// q1.processMsg();
// q1.enqueue("I need assistance with setting up my new device");
// q1.processMsg();
// q1.enqueue("The website is not loading properly on my browser.");
// q1.processMsg();
// q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
// q1.processMsg();
// q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
// q1.processMsg();
// q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
// q1.processMsg();
// q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
// q1.processMsg();
return 0;
}