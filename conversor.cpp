#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>

string decimalPraOutraBase(int numeroDecimal, int base) {

    if (numeroDecimal == 0) {
        return "0";
    }

    // Digitos para base até 62: 0-9, 26 A-Z, 26 a-z 2- 62
    std::string digitos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string resultado = "";
    bool negativo = false;

    if (numeroDecimal < 0) {
        negativo = true;
        numeroDecimal = -numeroDecimal;
    }

    while (numeroDecimal > 0) {
        int resto = numeroDecimal % base;
        resultado += digitos[resto];
        numeroDecimal /= base;
    }

    
    reverse(resultado.begin(), resultado.end());
    if (negativo) {
        if(base==2){
            for(int i =0; i<resultado.length();i++){
                if(resultado[i] == '0'){
                    resultado[i]='1';
                }
                else{
                    resultado[i]='0';
                }
            }
            int indice_first_zero = resultado.length()-1;
            while(resultado[indice_first_zero]=='1'){
                resultado[indice_first_zero] = '0';
                indice_first_zero--;
            }
            resultado[indice_first_zero] = '1';
            resultado = '1'+ resultado;
        }
        else{
            resultado = "-" + resultado;
        }
    }
    else{
        if(base==2){
            resultado = "0" + resultado;
        }
    }


    return resultado;
}



void limparCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

bool isBinario(string valor){
    for(int i=0; i<valor.length(); i++){
        if(valor.at(i)!='0' && valor.at(i)!='1'){
            return false;
        }

    }
    return true;
}
int converterBinarioPraDecimal(string valor){
    int cont{};
    if(valor[0]=='0'){
        for(int i=0; i<valor.length(); i++){
            if(valor.at(i)=='1'){
                cont+= pow(2,valor.length()-1-i);
            }

        }
        return cont;
    }
    else{
        string invertido = valor;
        for(int i =0; i<valor.length();i++){
            invertido[i] = (valor[i]=='0')? '1':'0';
        }
        int indice_first_zero = invertido.length()-1;
        while (indice_first_zero >= 0 && invertido[indice_first_zero] == '1') {
            invertido[indice_first_zero] = '0';
            indice_first_zero--;
        }
        if (indice_first_zero >= 0) {
            invertido[indice_first_zero] = '1';
        } else {
            invertido = '1' + invertido;
        }
        for(int i=0; i<invertido.length(); i++){
            if(invertido[i]=='1'){
                cont+= (1 << (invertido.length() - 1 - i));
            }
        }
        return -cont;
    }
}


int main(){
    int opcao_escolhida, valor_converter_decimal, base_conversao;
    bool valor_errado, valor_recebido;
    string valor_converter_binario, valor_convertido_binario;
    while(1){
        valor_errado = false;
        valor_recebido = false;
        cout<< "Digite a opção que você quer converter:\n";
        cout<< "Digite '1' para converter de decimal para outra base\n"; 
        cout<< "Digite '2' para converter binario para decimal\n";
        cout<<"Digite '0' para fechar o programa\n";
        cout<<" digite a opção:";
        cin>> opcao_escolhida;
        cout<<endl;
        switch (opcao_escolhida)
        {
        case 1:
            while(1){
                cout<< "digite o valor em decimal (inteiro):";
                cin>> valor_converter_decimal;
                if (cin.fail()) {
                    cout<< "valor invalido, tente novamente\n";
                    limparCin();
                    continue;
                }
                cout<< "digite a base (2 a 62):";
                cin>> base_conversao;
                if (cin.fail()) {
                    cout<< "valor invalido, tente novamente\n";
                    limparCin();
                    continue;
                }
                if (base_conversao < 2 || base_conversao > 62) {
                    cout<< "base invalido, tente novamente\n";
                    limparCin();
                    continue;
                }
                limparCin();
                valor_converter_decimal /=1;
                valor_convertido_binario  = decimalPraOutraBase(valor_converter_decimal, base_conversao);
                cout<< "o valor é "<< valor_convertido_binario<<endl;
                cout<<endl;
                valor_recebido = true;
                break;
            }
            
            break;
        case 2:
            while(1){
                cout<< "digite o valor em binario:";
                cin>> valor_converter_binario;
                cout<<endl;
                if(isBinario(valor_converter_binario)){
                    int valor_convertido_decimal = converterBinarioPraDecimal(valor_converter_binario);
                    cout<< "o valor é "<<valor_convertido_decimal<<endl;
                    valor_recebido = true;
                    break;
                }
                else{
                    cout<< "o valor digitado não é binário, digite 'o' para escolher outra opção\nou digite qualquer outro valor e tente novamente:";
                    char opcao;
                    cin>> opcao;
                    if(opcao=='o'){
                        break;
                    }
                    continue;
                }
            }
            
            break;
        case 0:
            cout<< "entendido, até a próxima\n";
            return 0;
        default:
            cout<<"valor incorreto, tente novamente\n\n";
            valor_errado = true;
            break;
        }
        if(valor_recebido){
            while (1){
                char opc_valor_recebido;
                cout<< "desja fazer mais alguma conversão? (s/n):";
                cin>>opc_valor_recebido;
                cout<< endl;

                if(opc_valor_recebido =='n'){
                    cout<< "entendido, até a próxima\n";
                    return 0;
                }
                else if (opc_valor_recebido== 's'){
                    break;
                }
                else{
                    string opc_valor_recebido_errado;
                    cout<<"valor invalido, digite 'x' para sair do programa ou qualquer outra tecla para voltar ao menu.\n digite aqui:";
                    cin>> opc_valor_recebido_errado;
                    if(opc_valor_recebido_errado=="x"){
                        cout<< "entendido, até a próxima\n";
                        return 0;
                    }
                    else{
                        break;
                    }
                }   
            }
            
            
                    
        }
        if(valor_errado){
            continue;
        }
    }
    
    return 0;
} 