#include "pedidos.h"

FilaPedidos::FilaPedidos() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

FilaPedidos::~FilaPedidos() {
    while (primeiro != nullptr) {
        NoPedido* temp = primeiro;
        primeiro = primeiro->proximo;
        delete temp;
    }
}

void FilaPedidos::adicionarPedido(const Pedido& pedido) {
    NoPedido* novo_pedido = new NoPedido;
    novo_pedido->pedido = pedido;
    novo_pedido->proximo = nullptr;
    if (primeiro == nullptr) {
        primeiro = novo_pedido;
    }
    else {
        ultimo->proximo = novo_pedido;
    }
    ultimo = novo_pedido;
    tamanho++;
}

Pedido FilaPedidos::removerPedido() {
    if (primeiro == nullptr) {
        throw std::runtime_error("Fila vazia!");
    }
    Pedido pedido_removido = primeiro->pedido;
    NoPedido* temp = primeiro;
    primeiro = primeiro->proximo;
    delete temp;
    tamanho--;
    return pedido_removido;
}

bool FilaPedidos::filaVazia() const {
    return (primeiro == nullptr);
}

int FilaPedidos::tamanhoFila() const {
    return tamanho;
}
