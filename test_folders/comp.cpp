#include <iostream>
#include <string>
class LehmanBros_Investment{
	private: 
		double secret_illegal_constant = 666.4485;
		double raw_investment_score;
		int access_number = 32982;
		std::string name;
	public:
		std::string investment_name(){
			return name; //Access data (no limit)
		}
        void change_name(std::string name2){
            name = name2; //Manipulate data (no limit)
        }
        void change_raw_score(int access_level, int score){
            if(access_level > 5){
                raw_investment_score = score; 
                    //manipulate data (with authorization gate)
            }
        }
        char grade(){
            double tot_score = raw_investment_score * secret_illegal_constant;
            if(tot_score > 700){
                return 'A'; // ONLY RETURNS LETTER GRADE
            }
            else{
                return 'B'; //Access data (Return type limited)
            }
        }
};

