/*


    [2 punkty] LeetCode Przygotwać bibliotekę wspomagającą tworzenie skróconych adresów URL.
    W tym celu może pomóc Zdefniowanie metody generotora, która jest testowana w pierwszym kroku testów.
    Na podstawie aktualnego stanu generatora (tablica 6 znaków) wyznacza następny stan.
    Tablicę stanu można dalej przechowywać w strukturze TinyUrlCodec
        Moduł: tinyurl
        Pliki z implementacją: TinyUrl.h/cpp
        Używana struktura danych: TinyUrlCodec
        Sygnatury metod:

        std::unique_ptr<TinyUrlCodec> Init();
        void NextHash(std::arrray<char, 6> *state);
        std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
        std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);

        Przestrzeń nazw: tinyurl
        Importy:

        #include <utility>
        #include <string>
        #include <array>
        #include <memory>

 */


#include <iostream>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <regex>

using namespace std;
char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};



struct TinyUrlCodec
        {
            string long_url;
            string short_url;
        };

string lpu(string sb_url)
{
    int rand_let;
    string ti_url;
    int tab[6] ;

    for (int i = 0; i<6; i++)
    {
        rand_let = rand() %25 +0;
        //cout << "random "<< rand_let<<endl;

        ti_url +=letters[rand_let];
        //cout<<ti_url<<endl;

    }
    sb_url +=ti_url;
    return sb_url;

}


int main() {

    srand( time( NULL ) );

    char LETTERS[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    string long_url;
    string t_u;
    regex patter ("http://www.(\\w).(\\w)\[   ^ ]");
    //cout<<"wprowadz url: ";
    //cin>>long_url;
    //cout<<long_url;
    int num_slash = 0;
    string sb_url;
    string url ;
    cout << "Wprowadz nazwe strony "<<endl;cin>>url;




    for (int i = 0 ; i<url.length();i++)
    {
        if (num_slash == 3)
        {
            break;
        }
        //cout<<url[i]<<endl;
        if (url[i] == '/')
        {
            num_slash++;
            //cout << "Number of slash "<< num_slash<<endl;
        }
        sb_url +=url[i];
    }

    //cout<<sb_url<<endl;
    //cout<<sb_url<<endl;
    string short_url = lpu(sb_url);
    cout<<short_url<<endl;

    TinyUrlCodec new_url =
            {
            url,
            short_url
            };

    //cout<< new_url.long_url << "<=>"<<new_url.short_url;
    return 0;
}
