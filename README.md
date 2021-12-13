# FileTransferApp

Thales Programming Challenge

- Observações de desenvolvimento:

Foi desenvolvido um software em C++ para transferência de arquivos em repositórios pré selecionados conforme enunciado "ThalesProgrammingChallenge.docx".

A IDE utilizada foi o QT Creator 6.0 com compilador MinGW 64bit. 

O software foi testado no sistema operacional Windows 10

- Descrição do software:

![image](https://user-images.githubusercontent.com/44126014/145903976-9d48d126-af55-466d-9a0a-0889ee66864e.png)


Dada uma expressão regular, um diretório de origem e um diretório de destino, o software copia todos arquivos que contém o nome aceito pela expressão regular fornecida.

Além da opção de rodar apenas uma vez, o software possui a opção de rodar automaticamente, o tempo mínimo entre cada atualização é de 1 segundo, podendo ser definido períodos maiores.

A opção de plotagem de gráfico gera dois arquivos no mesmo repositório de logs. Um arquivo contem a contagem de datas únicas que foram feitas transferências de arquivos, o segundo arquivo é um script para plot (.plt) que pode ser lido pelo software gnuplot. Exemplo de plot:
![image](https://user-images.githubusercontent.com/44126014/145903304-deee0951-e502-4963-96f2-4dfe7a8e3457.png)


- Menu Settings:


![image](https://user-images.githubusercontent.com/44126014/145906784-a121aa69-96ad-4ec3-8832-878c21cd4df5.png)

O software também conta com a opção de salvar/carregar configurações que atuam com os campos de texto (Regex, source, Destination, Refresh Rate);

E com a opção de seleção de diretório de arquivo de log (por default é definido como a pasta temp do usuário).



- Prevenção de erros:

Caso o programa inicie sem uma pasta de logs válida, será gerado uma caixa de alerta, e todas funções exceto a de trocar de diretório ficaram bloqueadas;

Caso não seja digitado nenhuma expressão regular, o programa irá perguntar se o usuário deseja continuar;

Ao utilizar o auto refresh, as funções em "Settings" e os campos de texto(Regex, Source, Destination, Refresh Rate) serão desativadas até que o botão Stop seja acionado;

Todas chamadas para abertura de arquivo estão em um if, caso o arquivo seja invalido irá gerar uma caixa de erro.



- Dificuldades:

Devido a um erro de compatibilidade do QT Creator 6.0 não pude utilizar a biblioteca QCustomPlot para fazer o plot dos gráficos em um objeto Widget no próprio software, como segunda alternativa, foi criada um rotina para escrever um script para plortar o grafico em .plt (interpretado pelo software gnuplot)


Alguns dos fóruns onde outras pessoas tiveram o mesmo problema:

https://www.qcustomplot.com/index.php/support/forum/2350

https://www.qcustomplot.com/index.php/support/forum/2399

https://www.qcustomplot.com/index.php/support/forum/2374
