//
// Created by kartytko on 11.03.17.
//

#include "GreatestProduct.h"
#include <iostream>
#include <vector>


void PrintVector(const std::vector<int> &v) {
    bool first = true;
    for(auto n : v) {
        if (!first) {
            std::cout<< ", ";
        } else {
            first = false;
        }
        std::cout << n;

    }
    std::cout<<std::endl;
}

//poniżej funkcja tworząca 4 wektory o zadanej długości k, do których wpisuje liczby:
//największe dodatnie, najmniejsze dodatnie, największe ujemne, najmniejsze ujemne.
//W zależności od ilości liczb ujemnych (negative_counter) w stosunku do liczb dodatnich (numbers.size()-(zero_counter+negative_counter))
//greatest_product przyjmuje inną wartość. Gdy greatest_product może być dodatni, wówczas czerpie czynniki z smallest_negative i greatest_positive.
//W innym wypadku - z greatest_negative i smallest_positive.

//Funckja ma błędy - nie działa poprawnie dla wszystkich danych!!!

//Pod tą funkcją znajduję się kolejna - licząca greatest_product dla k liczb dodatnich o złożoności O(n k)


int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector <int> greatest_positive;
    std::vector <int> smallest_positive;
    std::vector <int> greatest_negative;
    std::vector <int> smallest_negative;
    int counter = 0;
    int negative_counter = 0;
    int zero_counter = 0;
    int greatest_product = 1;

    if(numbers.size()==k){
        for(auto m : numbers)
            greatest_product = greatest_product * m;
        return greatest_product;
    }


    for (auto n : numbers){

        if(n<0){
            negative_counter ++;
        }
        if(n==0){
            zero_counter ++;
        }



        if(n>0){                                        //wektory dla liczb dodatnich;  k-wymiarowe przechowujące k największych dodatnich oraz k najmniejszych dodatnich
            if(greatest_positive.size()<k){             //greatest_positive   np. 6  7  10
                if(greatest_positive.size()==0){
                    greatest_positive.push_back(n);
                }
                else{
                    for(auto m : greatest_positive){
                        if(n>greatest_positive[greatest_positive.size()-1]){
                            greatest_positive.push_back(n);
                            break;
                        }
                        if(n<=greatest_positive[0]){
                            greatest_positive.insert(greatest_positive.begin(), n);
                            break;
                        }
                        if(n>m){
                            counter++;
                        }else{
                            greatest_positive.insert(greatest_positive.begin()+counter, n);
                            break;
                        }
                    }
                  //  PrintVector(greatest_positive);
                    //std::cout<<"gr pos up"<<std::endl;


                    counter = 0;
                }

            }else{
                if(n>=greatest_positive[0]){
                    greatest_positive.erase(greatest_positive.begin());
                    for(auto m : greatest_positive){
                        if(n>greatest_positive[greatest_positive.size()-1]){
                            greatest_positive.push_back(n);
                            break;
                        }

                        if(n>m){
                            counter++;
                        }else{
                            greatest_positive.insert(greatest_positive.begin()+counter, n);
                            break;
                        }
                    }
                    counter = 0;
                }
            }





            if(smallest_positive.size()<k){                         //smallest_positive     5  2  1
                if(smallest_positive.size()==0){
                    smallest_positive.push_back(n);
                }else{
                    for (auto m : smallest_positive){
                        if(n<smallest_positive[smallest_positive.size()-1]){
                            smallest_positive.push_back(n);
                            break;
                        }
                        if(n>=smallest_positive[0]){
                            smallest_positive.insert(smallest_positive.begin(), n);
                            break;
                        }
                        if(n<m){
                            counter++;
                        }else{
                            smallest_positive.insert(smallest_positive.begin()+counter, n);
                            break;
                        }
                    }
                    counter = 0;
                }

            }else{
                if(n<=smallest_positive[0]){
                    smallest_positive.erase(smallest_positive.begin());
                    for(auto m : smallest_positive){
                        if(n<smallest_positive[smallest_positive.size()-1]){
                            smallest_positive.push_back(n);
                            break;
                        }
                        if(n<m){
                            counter++;
                        }else{
                            smallest_positive.insert(smallest_positive.begin()+counter, n);
                            break;
                        }
                    }
                    counter = 0;
                }
            }
        }






        if(n<0){
            if(greatest_negative.size()<k){                     //największe ujemne ustawione    -4   -3   -1
                if(greatest_negative.size()==0){
                    greatest_negative.push_back(n);
                }else{
                    for(auto m : greatest_negative){
                        if(n > greatest_negative[greatest_negative.size()-1]){
                            greatest_negative.push_back(n);
                            break;
                        }
                        if(n<=greatest_negative[0]){
                            greatest_negative.insert(greatest_negative.begin(), n);
                            break;
                        }
                        if(n>m){
                            counter++;
                        }else{
                            greatest_negative.insert(greatest_negative.begin()+counter, n);
                            break;
                        }
                    }
                    counter = 0;
                }
            }else{
                if(n>=greatest_negative[0]){
                    greatest_negative.erase(greatest_negative.begin());
                    for (auto m : greatest_negative){
                        if(n>greatest_negative[greatest_negative.size()-1]){
                            greatest_negative.push_back(n);
                            break;
                        }

                        if(n>m){
                            counter++;
                        }else{
                            greatest_negative.insert(greatest_negative.begin()+counter, n);
                            break;
                        }
                    }
                    counter = 0;
                }
            }






            if(smallest_negative.size()<k){                 //najmniejsze ujemne   -7   -9    -10
                if(smallest_negative.size()==0){
                    smallest_negative.push_back(n);
                }else{
                    for(auto m : smallest_negative){
                        if(n<smallest_negative[smallest_negative.size()-1]){
                            smallest_negative.push_back(n);
                            break;
                        }
                        if(n>=smallest_negative[0]){
                            smallest_negative.insert(smallest_negative.begin(), n);
                            break;
                        }
                        if(n<m){
                            counter++;
                        }else{
                            smallest_negative.insert(smallest_negative.begin()+counter, n);
                            break;
                        }
                    }
                    counter = 0;
                }
            }else{
                if(n<=smallest_negative[0]){
                    smallest_negative.erase(smallest_negative.begin());
                    for (auto m : smallest_negative){
                        if(m<smallest_negative[smallest_negative.size()-1]){
                            smallest_negative.push_back(n);
                            break;
                        }
                        if(n<m){
                            counter++;
                        }
                        else{
                            smallest_negative.insert(smallest_negative.begin()+counter, n);
                            break;
                        }
                    }
                    counter = 0;
                }
            }

        }
        std::cout<<"great_pos"<<std::endl;
        PrintVector(greatest_positive);
        std::cout<<"small_pos"<<std::endl;
        PrintVector(smallest_positive);
        std::cout<<"small_neg"<<std::endl;
        PrintVector(smallest_negative);
        std::cout<<"great_neg"<<std::endl;
        PrintVector(greatest_negative);
    }



    int factors_amount = 0;
    int i=0;
    int j=0;


    while(factors_amount!=k) {
        if (numbers.size() - negative_counter >= k || (negative_counter >= k)) {    //jeśli liczb dodatnich jest wystarczająco dużo, żeby utworzyć liczbę dodatnią.

            if ((i + 1 <= smallest_negative.size() && j + 1 <= greatest_positive.size()) && factors_amount+1!=k) {
                if (smallest_negative[smallest_negative.size() - 1 - i] *
                    smallest_negative[smallest_negative.size() - 1 - (i + 1)] >
                    greatest_positive[greatest_positive.size() - 1 - j] *
                    greatest_positive[greatest_positive.size() - 1 - (j + 1)]) {
                    greatest_product = greatest_product * smallest_negative[smallest_negative.size() - 1 - i] *
                                       smallest_negative[smallest_negative.size() - 1 - (i + 1)];
                    factors_amount = factors_amount + 2;
                    i = i + 2;
                    std::cout << "tu jestem1 " << greatest_product << " " << factors_amount << std::endl;
                    if (factors_amount == k)
                        break;
                } else {
                    greatest_product = greatest_product * greatest_positive[greatest_positive.size() - 1 - j] *
                                       greatest_positive[greatest_positive.size() - 1 - (j + 1)];
                    factors_amount = factors_amount + 2;
                    j = j + 2;
                    std::cout << "tu jestem2 " << greatest_product << std::endl;
                    if (factors_amount == k)
                        break;
                }
            } else {
                if((smallest_negative.size()!=0 && greatest_positive.size()!=0) && (i==smallest_negative.size()-1 || j==greatest_positive.size()-1)){
                    if(greatest_positive[greatest_positive.size()-1-j]>smallest_negative[smallest_negative.size()-1-i]){
                        greatest_product=greatest_product*greatest_positive[greatest_positive.size()-1-j];
                        factors_amount++;
                        j++;
                        //continue;
                    }else{
                        greatest_product=greatest_product*smallest_negative[smallest_negative.size()-1-i];
                        i++;
                        factors_amount++;
                        //continue;
                    }
                }
                if (numbers.size() - negative_counter > k) {
                    greatest_product = greatest_product * greatest_positive[greatest_positive.size() - 1 - j];
                    factors_amount = factors_amount + 1;
                    j = j + 1;
                    std::cout << "tu jestem3 " << greatest_product << std::endl;
                    if(factors_amount==k)
                        break;
                }
                if (negative_counter > k) {
                    greatest_product = greatest_product * smallest_negative[smallest_negative.size() - 1 - i];
                    factors_amount++;
                    i++;
                    std::cout << "tu jestem4 " << greatest_product << std::endl;
                    if(factors_amount==k)
                        break;
                }
            }

        } else {
          // while (factors_amount != k) {
                if (i + 1 <= greatest_negative.size() && j + 1 <= smallest_positive.size()) {
                    if (greatest_negative[greatest_negative.size() - 1 - i] *
                        greatest_negative[greatest_negative.size() - 1 - (i + 1)] >
                        smallest_positive[smallest_positive.size() - 1 - j] *
                        smallest_positive[smallest_positive.size() - 1 - (j + 1)]) {
                        greatest_product = greatest_product * greatest_negative[greatest_negative.size() - 1 - i] *
                                           greatest_negative[greatest_negative.size() - 1 - (i + 1)];
                        factors_amount = factors_amount + 2;
                        j = j + 2;
                        std::cout << "tu jestem5 " << greatest_product << std::endl;
                    } else {
                        greatest_product = greatest_product * smallest_positive[smallest_positive.size() - 1 - j] *
                                           smallest_positive[smallest_positive.size() - 1 - (j + 1)];
                        factors_amount = factors_amount + 2;
                        i = i + 2;
                        std::cout << "tu jestem6 " << greatest_product << std::endl;
                    }
                } else {
                    /*if(numbers.size()-negative_counter>=k){
                        greatest_product = greatest_product * smallest_positive[smallest_positive.size()-1-i];
                        factors_amount = factors_amount +1;
                        i = i + 1;
                        std::cout<<"tu jestem7 "<<greatest_product << std::endl;
                    }*/
                    // if(negative_counter%2==0 && negative_counter>=k){
                    greatest_product = greatest_product * greatest_negative[greatest_negative.size() - 1 - j];
                    factors_amount++;
                    j++;
                    std::cout << "tu jestem8 " << greatest_product << std::endl;
                    //}
                }
          //  }
        }

    }


    smallest_negative.clear();
    smallest_positive.clear();
    greatest_negative.clear();
    greatest_positive.clear();
    return greatest_product;


}













// dla dodatnich i dowolnego k;
/*int GreatestProduct(const std::vector<int> &numbers, int k){
    int greatestproduct=1;
    int size = numbers.size();
    int smallest_number = 0;
    int greatest_number = 0;
    std::vector <int> factors;
    int first_iteration=true;
    int counter = 0;

    if(numbers.size()==k){
        for(auto m : numbers)
            greatestproduct = greatestproduct * m;
        return greatestproduct;
    }

    for(auto n : numbers){

        if(factors.size()<k){
            if(factors.size()==0){
                factors.push_back(n);
            }
            else{
                for (auto m : factors){
                    if(n>factors[factors.size()-1]){
                        factors.push_back(n);
                        break;
                    }
                    if(n>m){
                        counter++;
                    }
                    else{
                        factors.insert(factors.begin()+counter, n);
                        break;
//                        factors.push_back(n);
                    }

                }
                counter = 0;
            }
        }
        else{
            if(n<=factors[0]){
//                std::cout<<"tu jestem";
                continue;
            }
            else{
                factors.erase(factors.begin());
                for (auto m : factors){
                    if(n>factors[factors.size()-1]){
                        factors.push_back(n);
                        break;
                    }
                    if(n>m){
                        counter++;
                    }
                    else{
                        factors.insert(factors.begin()+counter, n);
                        break;
                    }
                }
                counter=0;
            }
        }
        PrintVector(factors);
    }

    for(auto m : factors){
        greatestproduct = greatestproduct * m;
//        std::cout <<greatestproduct;
    }

//    PrintVector(factors);
    factors.clear();
    PrintVector(factors);
    return greatestproduct;


}
*/



