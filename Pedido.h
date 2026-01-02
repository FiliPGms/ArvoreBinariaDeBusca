#ifndef PEDIDO_H
#define PEDIDO_H
// definição da estrutura Pedido
typedef struct pedido Pedido;

// basicas
Pedido* cadastrarPedido(int idPedido,char observacao[],char nomeCliente[],char nomePedido[] ,double valor);
void  excluirPedido(Pedido* ptr_p);
void imprimirPedido(const Pedido* ptr_p);

//getters
int obterIdPedido(Pedido* ptr_p);
const char* obterObservacao(const Pedido* ptr_p);
const char* obterNomeCliente(const Pedido* ptr_p);
const char* obterNomePedido(const Pedido* ptr_p);
double obterValorPedido(const Pedido* ptr_p);

//setters
void alterarObservacao(Pedido* ptr_p, const char novaObs[]);
void alterarNomeCliente(Pedido* ptr_p, const char novoNome[]);
void alterarValor(Pedido* ptr_p, double novoValor);
void alterarNomePedido(Pedido* ptr_p, const char novoNome[]);

#endif
