#include "ExScore.h"

ExScore::ExScore(string orig , int sc)
{
   origin = orig ; //строка с именем виновника ошибки
   iValue = sc; //сохраненное неправильное значение
}