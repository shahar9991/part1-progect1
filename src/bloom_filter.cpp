#include <iostream>
#include <string>
#include <vector>
using namespace std;


void workflow(){
    int input = get_input();
    is_valid_input = check_input();
    if (is_valid_input == FALSE){
        return;
    }

    vector bloom_filter;
    string to_do = to_do();
    if (to_do = "create"){
        bloom_filter = create_bloom_filter(input);
    }
    else if (to_do == "insert"){
        insert_to_filter(bloom_filter, input);
    }
    else if (to_do == "check"){
        check_if_in_filter(bloom_filter, input);
    }


}

int main(){
    while (TRUE){
        workflow();
    }
}
