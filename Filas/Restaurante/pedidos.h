#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <string>

struct Pedido {
    std::string nome_cliente;
    int num_pedido;
};

class FilaPedidos {
public:
    FilaPedidos();
    ~FilaPedidos();
    void adicionarPedido(const Pedido& pedido);
    Pedido removerPedido();
    bool filaVazia() const;
    int tamanhoFila() const;
private:
    struct NoPedido {
        Pedido pedido;
        NoPedido* proximo;
    };
    NoPedido* primeiro;
    NoPedido* ultimo;
    int tamanho;
};

#endif
