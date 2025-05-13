#include <iostream>
#include <math.h>

using namespace std;



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
    for(int i=0; i<valor.length(); i++){
        if(valor.at(i)=='1'){
            cont+= pow(2,valor.length()-1-i);
        }

    }
    return cont;
}

string converterDecimalPraBinario(int valor){
    string binarioInvertido = "";
    string binarioFinal = "";
    while(valor>=1){
        if(valor%2==0){
            binarioInvertido +="0";
        }
        else{
            binarioInvertido +="1";
        }
        valor/=2;
    }
    for(int i = binarioInvertido.length()-1; i>=0; i--){
        binarioFinal += binarioInvertido.at(i);
    }
    return binarioFinal;
}



int main(){
    int opcao_escolhida, valor_converter_decimal;
    bool valor_errado, valor_recebido;
    string valor_converter_binario, valor_convertido_binario;
    while(1){
        valor_errado = false;
        valor_recebido = false;
        cout<< "Digite a opção que você quer converter:\n";
        cout<< "Digite '1' para converter de decimal para binario\n"; 
        cout<< "Digite '2' para converter binario para decimal\n";
        cout<<"Digite '0' para fechar o programa\n";
        cout<<" digite a opção:";
        cin>> opcao_escolhida;
        cout<<endl;
        switch (opcao_escolhida)
        {
        case 1:
            cout<< "digite o valor em decimal (inteiro):";
            cin>> valor_converter_decimal;
            valor_converter_decimal /=1;
            valor_convertido_binario  = converterDecimalPraBinario(valor_converter_decimal);
            cout<< "o valor é "<< valor_convertido_binario<<endl;
            cout<<endl;
            valor_recebido = true;
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