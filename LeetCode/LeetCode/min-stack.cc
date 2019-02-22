#include<iostream>
#include<stack>
using namespace std;

class MinStack {
    public:
        void push(int number) {
            if(elements_.empty()) { elements_.emplace(0);
                stack_min_ = number;
            } else {
                elements_.emplace(static_cast<int64_t>(number) - stack_min_);
                if(number < stack_min_) { stack_min_ = number;
                }
            }
        }

        void pop() {
            auto diff = elements_.top();
            elements_.pop();
            if(diff < 0) {
                stack_min_ -= diff;
            }
        }

        int top() {
            if(elements_.top() > 0 ) {
                return stack_min_ + elements_.top();
            } else {
                return stack_min_ ;
            }
        }

        int getMin() {
            return stack_min_;
        }

    private:
        stack<int64_t> elements_;
        int stack_min_;
};
