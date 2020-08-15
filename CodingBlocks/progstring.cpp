#include<bits/stdc++.h>
using namespace std;

bool same(vector<int> a, vector<int> b) {
    for(int i=1;i<a.size();i++) {
        if(a[i] < b[i]) {
            return false;
        }
    }
    return true;
}

int progString(string s) {
    unordered_map<char,int> ind = {{'p',1},{'r',2},{'o',3},{'g',4},{'a',5},{'m',6},{'e',7}};
    vector<int> comp(8,0);
    string p = "programmer";
    for(char c:p) {
        comp[ind[c]]++;
    }

    int i=0,j=1,len=s.size();
    bool started = false;
    vector<bool> part(s.size(),false);
    vector<int> temp(8,0);
    int firsti,firstj;
    temp[ind[s[0]]]++;
    while(j<s.size()) {
        if(s[i] == s[j]) {
            if(temp[ind[s[i]]] >= comp[ind[s[i]]]) {
                i++;
                while(temp[ind[s[i]]] > comp[ind[s[i]]]) {
                    temp[ind[s[i]]]--;
                    i++;
                }
            } else {
                temp[ind[s[i]]]++;
            }
            j++;
        } else {
            temp[ind[s[j]]]++;
            j++;
        }

        if(same(temp,comp)) {
            started = true;
            if(j-i < len) {
                len = j-i;
                firsti = i;
                firstj = j;
            }
        }
    }
    temp.clear();
    temp.resize(8,0);
    len = s.size();
    int secondi=-1, secondj=-1;
    i=firstj,j=i+1;
    temp[ind[s[i]]]++;
    while(j<s.size()) {
        if(s[i] == s[j]) {
            if(temp[ind[s[i]]] >= comp[ind[s[i]]]) {
                i++;
                while(temp[ind[s[i]]] > comp[ind[s[i]]]) {
                    temp[ind[s[i]]]--;
                    i++;
                }
            } else {
                temp[ind[s[i]]]++;
            }
            j++;
        } else {
            temp[ind[s[j]]]++;
            j++;
        }

        if(same(temp,comp)) {
            started = true;
            if(j-i < len) {
                len = j-i;
                secondi = i;
                secondj = j;
            }
        }
    }

    if(secondi == -1) {
        temp.clear();
        temp.resize(8,0);
        len = s.size();
        i=0,j=i+1;
        temp[ind[s[i]]]++;
        while(j<=firsti) {
            if(s[i] == s[j]) {
                if(temp[ind[s[i]]] >= comp[ind[s[i]]]) {
                    i++;
                    while(temp[ind[s[i]]] > comp[ind[s[i]]]) {
                        temp[ind[s[i]]]--;
                        i++;
                    }
                } else {
                    temp[ind[s[i]]]++;
                }
                j++;
            } else {
                temp[ind[s[j]]]++;
                j++;
            }

            if(same(temp,comp)) {
                started = true;
                if(j-i < len) {
                    len = j-i;
                    secondi = i;
                    secondj = j;
                }
            }
        }
    }

    cout<<firsti<<" "<<firstj<<endl;
    cout<<secondi<<" "<<secondj<<endl;

    return max(firsti, secondi) - min(firstj, secondj) ;
}

int main() {

    cout<<progString("creunmnyzmosubijualwxjwswdzahqeevhpxvzlsvxjkknljifoyinblwnvcmzqowhkokwdjbimldnvqaaeovdzwzqtnhqmhtgaerqpcimlzysnwzftsoqaclhajhkyvozbivmhwcevkxrkmtaaxhwfwoybfbsftjujnivqsncuhjlqohbpyxmmqjcueebhavdyhzkbgzpgctjlgtyywptvkhrdtlrwouqyxmvlhdnynnlcajrjpjnvroqvxzavobnawwfkoornzmmvqmrcclvdeyqskdhafxcttmjsjlthmkbwueavuukdkfahnyankqehdfxysnnpwfbtstkpgspkcuhwgxaugbngclqtybxcuksnvvrqvbbjyrgyqnggitrmfsnxkeospesapgfcmjaysuphoxnorajwxuvcpuorsasbjnpwcsandjwfzzjtsjpdeyigyzdfozuhlctkgiysqauiqninnwurwjklfnznmvoadcezafeckmhytfiorlbffkkarirrkwolvavjaddvjytcorijbmbavcuvkxdreupgskweiwyssqcvktpvtkuggdtlubtoqcvnmaagureliuwtorzzwqevmhuxfyoyzuacjmgdrnsdlozuptyptrnzyizjaiaaqrkosmwfqygoecwcbtdgrpqmzotbsbtcdpqtmgciwqyzkwfpiswtmfebgjduutpfnclwnqxdegjlohewlnuqcvncndtextmqadnydwgbenhbfghkmktfabwwhqnktwfynzolwvcjrcbpdfldjoktcxxawipkbbuoirxqslolqpwzsuvnlsqxnhukivpynbkbjubjriioimbzyprdfbmaqzgevdgwcqjcjpapiobgiwkqrobnijuaxakqlcuocfwhfqwzvzopozrazfakhzxzoupittagyxsguizbhkajizmxfcogjjuzoxzkuwcgklevoaywnhadeyodeccmaksbyxawbhqdb")<<endl;
    return 0;
}

