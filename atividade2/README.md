# Projeto de Conclusão do Semestre
**Objetvo:** Elaborar um algorítmo para possibilitar gestão de informações bancárias.

> Utilizar *menu* para o usuário navegar no sistema sempre possibiltando acesso ao menu principal. O menu de opções deverá permitir ao usuário **SACAR, DEPOSITAR, EFETUAR PIX, CADASTRAR NOVO CLIENTE, TRANSFERIR DINHEIRO ENTRE CONTAS E CONSULTAR SALDO** 
> > Essa consulta deverá apresentar a informação da conta de um cliente específico **ou* de todas as contas cadastradas.

## Compilação 

```bash
gcc main.c Gerencia.c -o NOMEDOEXECUTÁVEL
```

## Documentação 
### Arquivo .tbd
A idéia inicial do projeto foi a de criar uma espécie de banco de dados, afim de não perder o conteúdo das contas cadastradas neste banco fictício, bem como facilitar o teste dos códigos durante a execução do projeto. 

O arquivo **banco.tbd** contém essas informações bancárias fictícias que serão puxadas pelo programa para serem trabalhadas por ele. A extensão do arquivo é uma abreviação de "*T*exto do *B*anco de *D*ados" 

### Gerencia.c e Gerencia.h 
Afim de facilitar a leitura do código, tendo em vista a primeira tentativa (cf. [439c033](https://github.com/gabrielcoelho/ial002-2023/commit/439c03374b42106dc1e27504a8e1cb7dfcaebffd)) de criação do banco ter passado das 400 linhas, com muito código parecido sendo utilizado de forma espalhada por todo o arquivo. Então, a partir do comit seguinte ao referenciado (cf. [556d792](https://github.com/GabrielCoelho/IAL002-2023/commit/556d79294b6245198b4da0660711ab3a9ba8a91c)), eu refatorei todo o código para torná-lo mais fácil de ler e navegar, bem como puxei algumas estruturas de código que se repetiam para funções próprias.

### Cliente.h 
Aqui se encontra a base do Struct no qual armazenaremos as contas cadastradas (provenientes do Arquivo TBD), e de todas as demais que forem criadas. 

### main.c 
Aqui temos o arquivo padrão, de onde todas as demais funções são chamadas. Ele é bem simples e fácil de ler pelos mesmos motivos descritos acima. 

###### Demais documentações e explicações dos códigos podem ser encontradas nos comentários do mesmo.
