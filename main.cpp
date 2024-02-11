#include <iostream>

using namespace std;

class combination
{
    public:

    protected:
    int calculate_combination(int n, int r);

    private:
    int factorial (int n);

};


int combination::calculate_combination(int n, int r)
{
    int totalCombination;
    //combination formula (n!/((n-r!)*r!))      
    totalCombination = factorial(n-r); //totalCombination = (n-r)!
    totalCombination *= factorial(r); //toatlCombination = (n-r)! * r!
    totalCombination = factorial(n) / totalCombination; //totalCombination = n! / ((n-r)! * r!)

    return (totalCombination);
}

int combination::factorial(int n)
{
    int fact=1;
    for (int i = n; i>0; i--)
    {
        fact *= i;
    }

    return fact;
}

class dice : protected combination
{
    public:
    int calculateTotalDiceRollCombinations(int totalDice, int diceFace=6);
    int showDiceFace(int diceFace=6);
    float calculateProbability(int sumInput, int diceNums=2, int diceFaces=6);
    private:
    int totalDiceFaces;
    int findCountSumEquals(int sumInput, int diceFace=6);
};


int dice::showDiceFace(int diceFace)
{
    int totalDistribution, count;
    totalDistribution = calculateTotalDiceRollCombinations(2,diceFace);

    std::cout << "Total Distribution : " << totalDistribution << std::endl;
    count=0;
    for(int iA =1; iA<=diceFace; iA++)
    {
        for(int iB =1; iB<=diceFace; iB++)
        {
              std::cout << count++ <<", iA: iB =" << iA << ":"<< iB << std::endl;  
        }
    }



}

float dice::calculateProbability(int sumInput, int diceNums,int diceFaces)
{

    float probility;

    probility = findCountSumEquals(sumInput,diceFaces);

    std::cout << "Find Sum Count" << probility << std::endl;
    probility = probility / calculateTotalDiceRollCombinations(diceNums,diceFaces);

    std::cout << "Probability " << probility << std::endl;
    return probility;

}

int dice::findCountSumEquals(int sumInput, int diceFace)
{
    int count;

    count =0;
    for(int iA =1; iA<=diceFace; iA++)
    {
        for(int iB =1; iB<=diceFace; iB++)
        {
              if ((iA+iB)== sumInput)
              {
                count++;
                std::cout << "Sum " << iA << ":" << iB << std::endl;
              }  
        }
    }

    return count;
}


int dice::calculateTotalDiceRollCombinations(int totalDice, int diceFace)
{
    int totalDiceRollComb;

    totalDiceRollComb = 1;
    for(int i = 0; i < totalDice; i++)
    {
      totalDiceRollComb *= calculate_combination(diceFace,1);
    }

    return totalDiceRollComb;
}


int main(int, char**){
    std::cout << "Hello, from dice-challenge!\n";

    dice diceObj;

    diceObj.showDiceFace();

    diceObj.calculateProbability(8, 2, 6); 
}
