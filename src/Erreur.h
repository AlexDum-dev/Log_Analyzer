#include <exception>
#include <string>
using namespace std;
 
class Erreur: public exception
{
public:
    Erreur(int numero=0, string const& phrase_erreur="", int niveau=0) throw()
         :m_numero(numero),m_phrase(phrase_erreur),m_niveau(niveau)
    {}
 
     virtual const char* what() const throw()
     {
         return m_phrase.c_str();
     }
     
     int getNiveau() const throw()
     {
          return m_niveau;
     }
    
    virtual ~Erreur() throw()
    {}
 
private:
    int m_numero;               //Numéro de l'erreur
    string m_phrase;            //Description de l'erreur
    int m_niveau;               //Niveau de l'erreur
};