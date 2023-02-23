#include <iostream>
#include "pedidos.h"

int main() {
    FilaPedidos fila;

    Pedido pedido1 = {"Joao", 1};
    Pedido pedido2 = {"Maria", 2};
    Pedido pedido3 = {"Jose", 3};
    Pedido pedido4 = {"Ana", 4};
    Pedido pedido5 = {"Carlos", 5};

    fila.adicionarPedido(pedido1);
    fila.adicionarPedido(pedido2);
    fila.adicionarPedido(pedido3);

    std::cout << "Tamanho da fila: " << fila.tamanhoFila() << std::endl;

    Pedido primeiro_pedido = fila.removerPedido();
    std::cout << "Removido pedido de " << primeiro_pedido.nome_cliente << std::endl;

    fila.adicionarPedido(pedido4);
    fila.adicionarPedido(pedido5);

    std::cout << "Tamanho da fila: " << fila.tamanhoFila() << std::endl;

    while (!fila.filaVazia()) {
        Pedido proximo_pedido = fila.removerPedido();
        std::cout << "Removido pedido de " << proximo_pedido.nome_cliente << std::endl;
    }

    return 0;
}
