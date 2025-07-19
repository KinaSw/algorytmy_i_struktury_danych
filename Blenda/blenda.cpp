#include <iostream>
#include <vector>



using namespace std;

struct Chlop{
    unsigned int C;
    unsigned int K;


    unsigned int max_dni;
    /*_dni() const {
        if (K > 0) {
            return (C + K - 1) / K;
        }
        return 0;
    }*/
};


unsigned long wydajnosc(const Chlop& chlop, unsigned int c){
    return ((2 * chlop.C - (c - 1) * chlop.K) * c) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    unsigned short t;
    cin>>t;
    while(t--){
        unsigned int n, d, m;
        cin >>n >> d >>m;
        unsigned int wymagane_tony=0;
        vector<Chlop> chlopi(n);
        for(unsigned int i=0; i<n; i++){
            cin>>chlopi[i].C>>chlopi[i].K;
            chlopi[i].max_dni=chlopi[i].C/chlopi[i].K+1;
        }

        for(unsigned int i=0; i<d; i++){
            unsigned int dzien;
            cin>>dzien;

            unsigned long calkowita_wydajnosc=0;

            for(unsigned int j=0; j<n; j++){

                unsigned int c;

                if(dzien<chlopi[j].max_dni){
                    c=dzien;
                } else{
                    c=chlopi[j].max_dni;
                }

                calkowita_wydajnosc +=wydajnosc(chlopi[j],c);

            }

            cout<< calkowita_wydajnosc << " ";
            if (calkowita_wydajnosc >= m) {
                wymagane_tony++;
            }
        }

        cout << "\n" << wymagane_tony << "\n";

    }
    return 0;
}