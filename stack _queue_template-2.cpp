// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Stacks-and-Queues.git

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>


// Add class Stack here
class Stack {
public:
  void validPara(std::string par) {
    std::vector<char> stack;
    bool loop_break = false;
    for (int i = 0; i < par.length(); i++) {
      if (par[i] == '(' || par[i] == '{' || par[i] == '[') {
        stack.push_back(par[i]);
      } else if (par[i] == ')' || par[i] == '}' || par[i] == ']') {
        if (stack.size() == 0) {
          loop_break = true;
          std::cout << "invalid" << std::endl;
          break;
        }
        if (par[i] == ')' && stack.back() != '(') {
          loop_break = true;
          break;
        }
        if (par[i] == '}' && stack.back() != '{') {
          loop_break = true;
          break;
        }
        if (par[i] == ']' && stack.back() != '[') {
          loop_break = true;
          break;
        } else {
          stack.pop_back();
        }
      }
    }
    if (stack.size() == 0 && loop_break == false) {
      std::cout << "Valid" << std::endl;
    }
    if (loop_break == true) {
      std::cout << "invalid" << std::endl;
    }
    if (stack.size() != 0 && loop_break == false) {
      std::cout << "invalid" << std::endl;
    }
  }

  int indexError(std::string par) {
    std::vector<char> stack;
    bool loop_break = false;
    for (int i = 0; i < par.length(); i++) {
      if (par[i] == '(' || par[i] == '{' || par[i] == '[') {
        stack.push_back(par[i]);
      } else if (par[i] == ')' || par[i] == '}' || par[i] == ']') {
        if (stack.size() == 0) {
          loop_break = true;
          return i;
        }
        if (par[i] == ')' && stack.back() != '(') {
          loop_break = true;
          return i;
        }
        if (par[i] == '}' && stack.back() != '{') {
          loop_break = true;
          return i;
        }
        if (par[i] == ']' && stack.back() != '[') {
          loop_break = true;
          return i;
        } else {
          stack.pop_back();
        }
      }
    }
    if (stack.size() != 0 && loop_break == false) {
      return stack.size();
    }
    return -1;
  }

  void minPara(std::string par) {
    std::vector<char> stack;
    bool loop_break = false;
    int num = 0;
    for (int i = 0; i < par.length(); i++) {
      if (par[i] == '(' || par[i] == '{' || par[i] == '[') {
        stack.push_back(par[i]);
      } else if (par[i] == ')' || par[i] == '}' || par[i] == ']') {
        if (stack.size() == 0) {
          loop_break = true;
          std::cout << 2 << std::endl;
          break;
        }
        if (par[i] == ')' && stack.back() != '(') {
          loop_break = true;
          num++;
        }
        if (par[i] == '}' && stack.back() != '{') {
          loop_break = true;
          num++;
        }
        if (par[i] == ']' && stack.back() != '[') {
          loop_break = true;
          num++;
        } else {
          stack.pop_back();
        }
      }
    }
    if (loop_break == true) {
      std::cout << num << std::endl;
    }
    if (loop_break == false && stack.size() == 0) {
      std::cout << num << std::endl;
    }
    if (loop_break == false && stack.size() != 0) {
      std::cout << stack.size() << std::endl;
    }
  }

  void scorePara(std::string par) {
    std::vector<char> stack;
    bool loop_break = false;
    int score = 0;
    int size_zero = 0;
    for (int i = 0; i < par.length(); i++) {
      if (par[i] == '(' || par[i] == '{' || par[i] == '[') {
        stack.push_back(par[i]);
      } else if (par[i] == ')' || par[i] == '}' || par[i] == ']') {
          if (stack.size() == 0) {
          size_zero = 1;
          std::cout << score << std::endl;
          break;
        }
        if (par[i] == ')' && stack.back() != '(') {
          loop_break = true;
        }
        if (par[i] == '}' && stack.back() != '{') {
          loop_break = true;
        }
        if (par[i] == ']' && stack.back() != '[') {
          loop_break = true;
        } else {
          stack.pop_back();
          score++;
        }
      }
    }
    if(size_zero != 1) {
    std::cout << score << std::endl;
    }
  }
};

// Add class Queue here
class Queue {
public:
  std::queue<std::string> queue;
  void enqueue(std::string msg) {
    std::string temp = msg;
    int char_count = 0;
    for (int i = 0; i < msg.length(); i++) {
      if (char_count == 8) {
        std::string string("");
        string.push_back(msg[i - 8]);
        temp.erase(temp.begin());
        string.push_back(msg[i - 7]);
        temp.erase(temp.begin());
        string.push_back(msg[i - 6]);
        temp.erase(temp.begin());
        string.push_back(msg[i - 5]);
        temp.erase(temp.begin());
        string.push_back(msg[i - 4]);
        temp.erase(temp.begin());
        string.push_back(msg[i - 3]);
        temp.erase(temp.begin());
        string.push_back(msg[i - 2]);
        temp.erase(temp.begin());
        string.push_back(msg[i - 1]);
        temp.erase(temp.begin());
        reverse(string.begin(), string.end());
        queue.push(string);
        char_count = 0;
      }
      if (temp.length() != 0 && i == msg.length() - 1) {
        std::string string("");
        for (int h = temp.length(); h >= 0; h--) {
          string.push_back(temp[h]);
        }
        queue.push(string);
        reverse(string.begin(), string.end());
      }
      char_count++;
    }
  }

  void processMsg() {
    std::string full("");
    for (; !queue.empty(); queue.pop()) {
      if (full == "") {
        reverse(queue.front().begin(), queue.front().end());
        full = queue.front();
      } else {
        reverse(queue.front().begin(), queue.front().end());
        full = full + queue.front();
      }
    }
    std::cout << full << std::endl;
  }
};
// Remove comments before testing and do not change anything in main function
int main() {
Stack s1;
// s1.validPara("(([]))");
s1.minPara("(([]))");
s1.scorePara("(([]))");
// s1.validPara("(([])");
// std::cout<<s1.indexError("(([))")<<std::endl;
s1.minPara("(([])");
// s1.validPara("(([{}))");
// std::cout<<s1.indexError("(([[}])")<<std::endl;
s1.minPara("(([{}))");
s1.scorePara("(([{}))");
// std::cout<<s1.indexError("({}[]()[)")<<std::endl;
// s1.validPara("(([))");
s1.minPara("(([))");
// std::cout<<s1.indexError("[({)]")<<std::endl;
// s1.validPara("(([{[{({})}]}]))");
s1.minPara("(([{[{({})}]}]))");
s1.scorePara("(([{[{({})}]}]))");
// s1.validPara("(([[{[{({})}]))");
// s1.validPara("(([[{[{({})}]}])]))");
s1.scorePara("(([[{[{({})}]}])]))");
// std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
// s1.validPara("(())");
// s1.validPara("(())");
// s1.validPara("void function(){}");
s1.scorePara("void function(){}");
// s1.validPara("void function(");
s1.minPara("void function(");
// s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
// s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
// s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
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