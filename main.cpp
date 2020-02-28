#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <time.h>

using namespace std;

void printGameInstructions();
void enterCatName(string *catName);
void initializeCatFoodsMap (map<int, string> *catFoods);
void initializeQuestionsMap(map<int, string> *catQuestions);
void initializeAnswersMap(map<int, string> *catAnswers);
bool answerQuestion(map<int, string> catAnswers, int randNum, float *catWeight, map<int, string> :: iterator it);
int askQuestion(map<int, string> *catQuestions, map<int, string> :: iterator it);

void startGame();

int const MAX = 24;
int const MIN = 1;

int main(){
    startGame();
    return 0;
}

void startGame() {
    string catName;
    float catWeight = 0.8;
    int catAge = 0;
    int randNum;
    map<int, string> :: iterator it;
    map<int, string> catQuestions;
    map<int, string> catAnswers;
    map<int, string> catFoods;

    printGameInstructions();
    enterCatName(&catName);
    initializeAnswersMap(&catAnswers);
    initializeQuestionsMap(&catQuestions);
    initializeCatFoodsMap(&catFoods);

    while(catAge<15) {
        it = catFoods.begin();
        it = catFoods.find(catAge);
        cout << "Your cat "<< catName <<" has an appetite for " << it->second << endl <<
        "Please answer the question to feed it!" << endl;

        it = catFoods.end();
        randNum = askQuestion(&catQuestions,it);

        cout << randNum <<endl;

        if(!answerQuestion(catAnswers,randNum, &catWeight,it)){
            cout << "Poor "
                 << catName << " died because you starved him to death at the age of " << catAge<< "!";
            return;
        }
        cout<< "Map size: " << catQuestions.size();
        catWeight++;
        catAge++;
        cout << "----------------------------------------------------------------------"<<endl;
    }

    cout << "Your cat "
         << catName << " died at the old age of 15. It has lived a healthy life thanks to you weighing "
         << catWeight << " kilograms!";
}

int askQuestion(map<int, string> *catQuestions, map<int, string> :: iterator it){
    srand ( time(NULL) );
    int randNum = rand() % (MAX - MIN + 1) + MIN;

    if((*catQuestions).find(randNum) == (*catQuestions).end() ){
        askQuestion(catQuestions, it);
    }
    it = (*catQuestions).begin();
    it = (*catQuestions).find(randNum);
    cout << it->second << endl;

    (*catQuestions).erase(randNum);

    it = (*catQuestions).end();
    return randNum;
}
bool answerQuestion(map<int, string> catAnswers, int randNum, float *catWeight, map<int, string> :: iterator it) {
    it = catAnswers.begin();
    it = catAnswers.find(randNum);
    string answer;
    cout << "Current cat weight: " << *catWeight << endl;
    cout << "Please answer the question!"<<endl;
    getline(cin, answer);

    cout<< "Answer: " << answer;
    if(answer.compare(it->second) == 0){
        it = catAnswers.end();
        return true;
    } else {
        cout << "Wrong answer! Your cat lost weight"<<endl;
        it = catAnswers.end();
        *catWeight -= 0.5;
        return *catWeight <= 0 ? false : answerQuestion(catAnswers, randNum, catWeight, it);
    }
}
void printGameInstructions(){
    cout << "Game instructions: " << endl <<
         "You will be given trivia questions answer them and your cat will get fatter. " << endl <<
         "Your cat's weight is your life points. If you don't answer correctly your cat will " << endl <<
         "loose 0,500 kilograms for each incorrect question and gain 1 kg for each correct. " << endl <<
         "if you cat reaches 0 then you have starved your cat to death and the game ends. If you " << endl <<
         "answered 3 or more questions in a row correctly your cats gains 1,5 kilograms." << endl <<
         "after each round your cat grows one year older. When your cat reaches 15, you have beat " << endl <<
         "the game and you cat dies happy and fat!" << endl <<
         "HAVE FUN" << endl <<
         "----------------------------------------------------------------------------------------" << endl;
}
void enterCatName(string *pCatName){
    string catName;

    cout << "You have recently adopted an kitten. What is its name?" << endl;
    getline(cin, catName);

    *pCatName=catName;
}
void initializeQuestionsMap(map<int, string> *catQuestions){
    (*catQuestions)[1] = "What is the proper term for a group of kittens?";
    (*catQuestions)[2] = "All cats are born with what color eyes?";
    (*catQuestions)[3] = "What percentage of a cat's bones are in its tail?";
    (*catQuestions)[4] = "How many different sounds can a cat make?";
    (*catQuestions)[5] = "How many breeds of domestic cat are there worldwide?";
    (*catQuestions)[6] = "What is the normal body temperature of a cat?(In celsius)";
    (*catQuestions)[7] = "What breed of cat has a reputation for being cross-eyed?";
    (*catQuestions)[8] = "What breed of domestic cat has the longest fur?";
    (*catQuestions)[9] = "Which country has more cats per person than any other country in the world?";
    (*catQuestions)[10] = "How many cats did Abraham Lincoln have in the White House?";
    (*catQuestions)[11] = "What is a group of cats called?";
    (*catQuestions)[12] = "What is the extreme fear of cats called?";
    (*catQuestions)[13] = "What is the largest breed of cat?";
    (*catQuestions)[14] = "What percent of people identify as cat people?";
    (*catQuestions)[15] = "How many teeth does an adult cat have?";
    (*catQuestions)[16] = "How much did the world's heaviest cat weigh?(Kilograms?)";
    (*catQuestions)[17] = "How fast can cats run?(kph)";
    (*catQuestions)[18] = "What cartoon cat is buddies with a dog named Odie?";
    (*catQuestions)[19] = "How old was the world's oldest cat?(years)";
    (*catQuestions)[20] = "How many kittens can a single pair of cats and their offspring produce in 7 years?";
    (*catQuestions)[21] = "How many whiskers does a cat have?";
    (*catQuestions)[22] = "Where do cats have most of their sweat glands?";
    (*catQuestions)[23] = "What is a female cat called?";
    (*catQuestions)[24] = "How many muscles does a cat have in each ear?";
}
void initializeAnswersMap(map<int, string> *catAnswers){
    (*catAnswers)[1] = "kindle";
    (*catAnswers)[2] = "blue";
    (*catAnswers)[3] = "10";
    (*catAnswers)[4] = "100";
    (*catAnswers)[5] = "70";
    (*catAnswers)[6] = "39";
    (*catAnswers)[7] = "Siamese";
    (*catAnswers)[8] = "Persian";
    (*catAnswers)[9] = "New Zealand";
    (*catAnswers)[10] = "4";
    (*catAnswers)[11] = "clowder";
    (*catAnswers)[12] = "Ailurophobia";
    (*catAnswers)[13] = "Maine Coons";
    (*catAnswers)[14] = "11";
    (*catAnswers)[15] = "30";
    (*catAnswers)[16] = "21";
    (*catAnswers)[17] = "48";
    (*catAnswers)[18] = "Garfield";
    (*catAnswers)[19] = "38";
    (*catAnswers)[20] = "370000";
    (*catAnswers)[21] = "24";
    (*catAnswers)[22] = "paws";
    (*catAnswers)[23] = "queen";
    (*catAnswers)[24] = "32";
}
void initializeCatFoodsMap (map<int, string> *catFoods) {
    (*catFoods)[0] = "milk";
    (*catFoods)[1] = "chicken";
    (*catFoods)[2] = "turkey";
    (*catFoods)[3] = "beef";
    (*catFoods)[4] = "eggs";
    (*catFoods)[5] = "fish";
    (*catFoods)[6] = "potatoes";
    (*catFoods)[7] = "cheese";
    (*catFoods)[8] = "peppers";
    (*catFoods)[9] = "bread";
    (*catFoods)[10] = "avocado";
    (*catFoods)[11] = "salmon";
    (*catFoods)[12] = "dry cat food";
    (*catFoods)[13] = "wet cat food";
    (*catFoods)[14] = "rice";
}
