#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Declaração de variáveis globais para armazenar a pontuação de cada metodologia
int metoCascata, metoIncremental, metoEspiral, metoPrototipagem;
bool confimacaoResposta = true;

// Função que exibe o logo inicial do programa
void LogoInicial() {
    system("cls"); // Limpa a tela do console
    // Configura o código da página para UTF-8 (apenas no Windows)
    SetConsoleOutputCP(CP_UTF8);

    // Exibindo a arte ASCII usando uma string raw
    cout << R"(
██████╗░██╗░░░██╗██╗██╗░░░░░██████╗░███╗░░░███╗░█████╗░██████╗░
██╔══██╗██║░░░██║██║██║░░░░░██╔══██╗████╗░████║██╔══██╗██╔══██╗
██████╦╝██║░░░██║██║██║░░░░░██║░░██║██╔████╔██║███████║██████╔╝
██╔══██╗██║░░░██║██║██║░░░░░██║░░██║██║╚██╔╝██║██╔══██║██╔═══╝░
██████╦╝╚██████╔╝██║███████╗██████╔╝██║░╚═╝░██║██║░░██║██║░░░░░
╚═════╝░░╚═════╝░╚═╝╚══════╝╚═════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░░░░
)" << endl;
}

// Declaração da função responsável pela recomendação de metodologia
void CodeRecomendacao();
void UltimoResultado();
void VantagensEDesvantagens();

// Função que exibe o menu inicial e coleta a escolha do usuário
void PainelInicial() {
    LogoInicial();
    string escolha;

    cout << "\nEscolha uma alternativa abaixo!" << endl;

    cout << "\n1. Realizar questionário" << endl;
    cout << "2. Último resultado" << endl;
    cout << "3. Vantagens dos métodos" << endl;
    cout << "0. Para sair" << endl;
    cout << "\nDigite a sua escolha: ";
    cin >> escolha;

    if (escolha == "1") {
        CodeRecomendacao(); // Chama a função que faz a recomendação baseada nas respostas
    }
    else if (escolha == "2") {
        UltimoResultado();
    }
    else if (escolha == "3") {
        VantagensEDesvantagens();
    }
    else if (escolha == "0") {
        return;
    }
    else {
        PainelInicial();
    }
}

// Função que decide e exibe o resultado final, mostrando qual metodologia é mais adequada
void DecisaoResultado() {
    LogoInicial();
    cout << "\nPontuacao para decisao!" << endl;
    cout << "\nMetodo Cascata: " << metoCascata << " pontos" << endl;
    cout << "Metodo Incremental: " << metoIncremental << " pontos" << endl;
    cout << "Metodo Espiral: " << metoEspiral << " pontos" << endl;
    cout << "Metodo Prototipagem: " << metoPrototipagem << " pontos" << endl;

    int numeroMaior = metoCascata; // Inicia com o método Cascata como o mais pontuado
    string nomeMaior = "Cascata";

    // Verifica qual método tem a maior pontuação
    if (numeroMaior < metoIncremental) {
        numeroMaior = metoIncremental;
        nomeMaior = "Incremental";
    }
    if (numeroMaior < metoEspiral) {
        numeroMaior = metoEspiral;
        nomeMaior = "Espiral";
    }
    if (numeroMaior < metoPrototipagem) {
        numeroMaior = metoPrototipagem;
        nomeMaior = "Prototipagem";
    }

    cout << "\nO Ideal para o seu uso é o Metodo " << nomeMaior << " com " << numeroMaior << " pontos!" << endl;

    string confirmar;
    cout << "\nDigite algo e enter para voltar ao menu: ";
    cin >> confirmar;
    PainelInicial(); // Retorna ao menu inicial
}

void MostrarCascata() {
    system("cls");
    LogoInicial();
    cout << "\nVoce escolheu o Modelo Cascata.\n" << endl;
    cout << "Explicação:\n" << endl;
    cout << "O modelo Cascata é um processo sequencial de desenvolvimento de software, "
        "onde cada fase deve ser concluida antes de a proxima começar. As fases incluem "
        "requisitos, design, implementação, verificação e manutenção.\n" << endl;
    cout << "Vantagens:\n" << endl;
    cout << "- Simplicidade e facilidade de uso.\n";
    cout << "- Facilita o gerenciamento de projetos devido a natureza sequencial.\n";
    cout << "- Cada fase tem um objetivo bem definido.\n";
    string confirmar;
    cout << "\nDigite algo e enter para voltar ao menu anterior: ";
    cin >> confirmar;
    VantagensEDesvantagens();
}

void MostrarEspiral() {
    system("cls");
    LogoInicial();
    cout << "\nVoce escolheu o Modelo Espiral.\n" << endl;
    cout << "Explicação:\n" << endl;
    cout << "O modelo Espiral combina elementos do modelo Cascata e prototipagem, "
        "e adiciona a iteração. O processo passa por varias fases, cada uma abordando "
        "riscos de forma incremental, repetindo-se em 'espirais' até o produto final ser obtido.\n" << endl;
    cout << "Vantagens:\n" << endl;
    cout << "- Melhora a gestao de riscos.\n";
    cout << "- Flexibilidade para mudancas durante o desenvolvimento.\n";
    cout << "- Adequado para projetos grandes e complexos.\n";
    string confirmar;
    cout << "\nDigite algo e enter para voltar ao menu anterior: ";
    cin >> confirmar;
    VantagensEDesvantagens();
}

void MostrarPrototipagem() {
    system("cls");
    LogoInicial();
    cout << "\nVocê escolheu o Modelo de Prototipagem.\n" << endl;
    cout << "Explicação:\n" << endl;
    cout << "O modelo de Prototipagem envolve a criação de prototipos do software que "
        "são apresentados ao cliente para feedback. Com base no feedback, o protótipo "
        "é refinado até atingir a versão final.\n" << endl;
    cout << "Vantagens:\n" << endl;
    cout << "- Reduz a incerteza e riscos ao fornecer uma visualização inicial do sistema.\n";
    cout << "- Melhora a comunicação com o cliente.\n";
    cout << "- Permite ajustes antes de iniciar o desenvolvimento completo.\n";
    string confirmar;
    cout << "\nDigite algo e enter para voltar ao menu anterior: ";
    cin >> confirmar;
    VantagensEDesvantagens();
}

void MostrarIncremental() {
    system("cls");
    LogoInicial();
    cout << "Você escolheu o Modelo Incremental.\n" << endl;
    cout << "Explicação:\n" << endl;
    cout << "o modelo Incremental, o desenvolvimento do software e feito em incrementos. "
        "Cada incremento entrega uma parte funcional do sistema final, aumentando "
        "gradativamente até que todas as funcionalidades estejam implementadas.\n" << endl;
    cout << "Vantagens:\n" << endl;
    cout << "- Entrega antecipada de partes funcionais do sistema.\n";
    cout << "- Menor risco de falha do projeto.\n";
    cout << "- Melhor adaptação a mudanças de requisitos.\n";
    string confirmar;
    cout << "\nDigite algo e enter para voltar ao menu anterior: ";
    cin >> confirmar;
    VantagensEDesvantagens();
}

void VantagensEDesvantagens() {
    string escolhaDoUser;
    system("cls");
    LogoInicial();
    cout << "\nDe qual método gostaria de ver?" << endl;
    cout << "\n1. Modelo Cascata" << endl;
    cout << "2. Modelo Incremental" << endl;
    cout << "3. Modelo Espirala" << endl;
    cout << "4. Modelo Prototipagem" << endl;
    cout << "0. " << "para voltar ao menu" << endl;
    cout << "\nDigite a sua escolha: ";
    cin >> escolhaDoUser;

    if (escolhaDoUser == "1") MostrarCascata();
    else if (escolhaDoUser == "2") MostrarIncremental();
    else if (escolhaDoUser == "3") MostrarEspiral();
    else if (escolhaDoUser == "4") MostrarPrototipagem();
    else if (escolhaDoUser == "0") PainelInicial();
    else VantagensEDesvantagens();
}

// Função genérica que realiza as perguntas ao usuário e atribui pontos para as metodologias
void CodedeRecco(string pergunta, string resposta1, string resposta2, string set1a, string set1b, string set2a, string set2b) {
    string escolhaAqui;
    system("cls");
    LogoInicial();
    cout << "\n" << pergunta << endl;
    cout << "\n1. " << resposta1 << endl;
    cout << "2. " << resposta2 << endl;
    cout << "0. " << "para voltar ao menu" << endl;
    cout << "\nDigite a sua escolha: ";
    cin >> escolhaAqui;

    if (escolhaAqui == "1")
    {
        if (set1a == "AdicionarPrototipagem") metoPrototipagem++;
        if (set1a == "AdicionarIncremental") metoIncremental++;
        if (set1a == "AdicionarEspiral") metoEspiral++;
        if (set1a == "AdicionarCascata") metoCascata++;

        if (set1b == "AdicionarPrototipagem") metoPrototipagem++;
        if (set1b == "AdicionarIncremental") metoIncremental++;
        if (set1b == "AdicionarEspiral") metoEspiral++;
        if (set1b == "AdicionarCascata") metoCascata++;
    }
    else if (escolhaAqui == "2")
    {
        if (set2a == "AdicionarPrototipagem") metoPrototipagem++;
        if (set2a == "AdicionarIncremental") metoIncremental++;
        if (set2a == "AdicionarEspiral") metoEspiral++;
        if (set2a == "AdicionarCascata") metoCascata++;

        if (set2b == "AdicionarPrototipagem") metoPrototipagem++;
        if (set2b == "AdicionarIncremental") metoIncremental++;
        if (set2b == "AdicionarEspiral") metoEspiral++;
        if (set2b == "AdicionarCascata") metoCascata++;
    }
    else if (escolhaAqui == "0") confimacaoResposta = false;
}

// Função principal que chama a função de recomendação
void CodeRecomendacao() {
    confimacaoResposta = true;
    metoCascata = 0, metoEspiral = 0, metoIncremental = 0, metoPrototipagem = 0;
    if (confimacaoResposta == true) CodedeRecco("Qual é o tamanho e a estrutura da equipe?", "Equipe pequena", "Equipe grande", "AdicionarPrototipagem", "Não", "AdicionarIncremental", "AdicionarEspiral");
    if (confimacaoResposta == true) CodedeRecco("Qual é a experiência da equipe com diferentes métodos de desenvolvimento?", "Experiência com ágil", "Experiência com métodos tradicionais", "AdicionarIncremental", "AdicionarEspiral", "AdicionarCascata", "Não");
    if (confimacaoResposta == true) CodedeRecco("Qual é a complexidade do projeto?", "Projeto complexo", "Projeto menos complexo", "AdicionarEspiral", "Não", "AdicionarIncremental", "AdicionarPrototipagem");
    if (confimacaoResposta == true) CodedeRecco("Quais são os requisitos de mudança durante o desenvolvimento?", "Mudanças frequentes", "Mudanças raras", "AdicionarEspiral", "AdicionarPrototipagem", "AdicionarCascata", "Não");
    if (confimacaoResposta == true) CodedeRecco("Qual é o prazo para a entrega do projeto?", "Prazo curto", "Prazo longo", "AdicionarIncremental", "Não", "AdicionarCascata", "Não");
    if (confimacaoResposta == true) CodedeRecco("Qual é o orçamento disponível?", "Orçamento limitado", "Orçamento flexível", "AdicionarIncremental", "Não", "AdicionarEspiral", "Não");
    if (confimacaoResposta == true) CodedeRecco("Qual é o nível de colaboração necessário entre as partes interessadas?", "Alta colaboração", "Colaboração formal", "AdicionarEspiral", "AdicionarPrototipagem", "AdicionarCascata", "Não");
    if (confimacaoResposta == true) CodedeRecco("Quais são as expectativas de documentação e planejamento?", "Documentação leve e flexível", "Documentação extensiva", "AdicionarPrototipagem", "AdicionarIncremental", "AdicionarCascata", "Não");
    if (confimacaoResposta == true) CodedeRecco("Quais ferramentas e tecnologias a equipe está utilizando?", "Ferramentas que suportam iterações", "Ferramentas de planejamento e documentação", "AdicionarIncremental", "AdicionarEspiral", "AdicionarCascata", "Não");
    if (confimacaoResposta == true) CodedeRecco("Qual é o nível de maturidade do processo de desenvolvimento da equipe?", "Equipe em estágio inicial", "Equipe madura", "AdicionarPrototipagem", "AdicionarIncremental", "AdicionarEspiral", "AdicionarCascata");
    if (confimacaoResposta == true) CodedeRecco("Qual é a natureza do projeto?", "Projeto inovador", "Projeto de manutenção", "AdicionarPrototipagem", "Não", "AdicionarIncremental", "Não");
    if (confimacaoResposta == true) CodedeRecco("Qual é o nível de envolvimento do cliente?", "Alta participação", "Baixa participação", "AdicionarPrototipagem", "AdicionarEspiral", "AdicionarCascata", "Não");
    if (confimacaoResposta == true) CodedeRecco("Qual é a criticidade do projeto?", "Alta criticidade", "Baixa criticidade", "AdicionarEspiral", "Não", "AdicionarIncremental", "AdicionarCascata");
    if (confimacaoResposta == true) CodedeRecco("Qual é o perfil do usuário final?", "Usuários técnicos", "Usuários não técnicos", "AdicionarIncremental", "AdicionarEspiral", "AdicionarPrototipagem", "AdicionarIncremental");
    if (confimacaoResposta == true) CodedeRecco("Qual é a capacidade da equipe para lidar com mudanças de escopo?", "Alta flexibilidade", "Baixa flexibilidade", "AdicionarPrototipagem", "AdicionarEspiral", "AdicionarPrototipagem", "AdicionarIncremental");
    if (confimacaoResposta == true) CodedeRecco("Qual é o impacto dos requisitos não funcionais?", "Impacto significativo", "Impacto moderado", "AdicionarEspiral", "AdicionarPrototipagem", "AdicionarIncremental", "AdicionarCascata");
    
    if (confimacaoResposta == false) PainelInicial();

    if (confimacaoResposta == true) DecisaoResultado(); // Chama a função que decide e exibe o resultado final
}

void UltimoResultado() {
    LogoInicial();

    if (metoCascata == 0 and metoIncremental == 0 and metoPrototipagem == 0 and metoEspiral == 0) {
        cout << "\nNão possui nenhum resultado passado armazenado!" << endl;
        cout << "Tente realizar um questionário <.<" << endl;
        string confirmar;
        cout << "\nDigite algo e enter para voltar ao menu: ";
        cin >> confirmar;
        PainelInicial();
    }
    else {
        cout << "\nPontuacao para decisao passada!" << endl;
        cout << "\nMetodo Cascata: " << metoCascata << " pontos" << endl;
        cout << "Metodo Incremental: " << metoIncremental << " pontos" << endl;
        cout << "Metodo Espiral: " << metoEspiral << " pontos" << endl;
        cout << "Metodo Prototipagem: " << metoPrototipagem << " pontos" << endl;
        string confirmar;
        cout << "\nDigite algo e enter para voltar ao menu: ";
        cin >> confirmar;
        PainelInicial();
    }
}

// Função principal do programa
int main() {
    PainelInicial(); // Inicia o programa exibindo o painel inicial

    return 0;
}