//#include "Handler.h"
//
//
///**
// * @brief Apaga uma das linhas da janela de visualizacao
// *
// */
//void clearline()
//{
//	int x,y;
//	getCursorXY(x,y);
//	gotoXY(0,y);
//	for(x = 0; x < 80; x++) {cout << " ";};
//	gotoXY(0,y);
//}
//
//
//
//
///**
// * @brief Verifica se uma entrada e valida
// *
// * Verifica se uma entrada e valida atraves do seu tamanho
// *
// * @param Entrada pelo utilizador
// * @param Tamanho a verificar
// *
// */
//void getEntrada(string &entrada, unsigned tamanho)
//{
//	bool valid = false;
//	int x, y;
//
//	getCursorXY(x,y);
//	for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//	gotoXY(x,y);
//	do
//	{
//		getline(cin, entrada);
//
//		if (entrada.size() > tamanho)
//			cout << "Entrada invalida. So pode ter " << tamanho << " caracteres.\n";
//		else if (find(entrada.begin(), entrada.end(), '_') != entrada.end())
//			cout << "Entrada invalida. Nao pode usar underscores.\n";
//		else if (cin.fail())
//		{
//			cout << "Erro de leitura. Introduza uma entrada valida.\n";
//			cin.clear();
//		}
//		else
//			valid = true;
//
//		if (!valid)
//		{
//			gotoXY(x,y);
//			for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//			gotoXY(x,y);
//		}
//	} while (!valid);
//}
//
//
//
//
///**
// * @brief Verifica se uma entrada e valida
// *
// *
// * @param Entrada pelo utilizador
// *
// */
//void getEntrada(float &entrada)
//{
//	bool valid = false;
//	int x, y;
//	getCursorXY(x,y);
//	for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//	gotoXY(x,y);
//	do
//	{
//		cin >> entrada;
//
//		if (cin.fail())
//		{
//			cout << "Erro de leitura. Introduza uma entrada valida.\n";
//			cin.clear();
//		}
//		else
//			valid = true;
//
//		if (!valid)
//		{
//			gotoXY(x,y);
//			for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//			gotoXY(x,y);
//		}
//		cin.ignore(1000, '\n');
//	} while (!valid);
//}
//
//
//
//
//
//
///**
// * @brief Verifica se uma entrada e valida
// *
// *
// * @param Entrada pelo utilizador
// *
// */
//void getEntrada(int &entrada)
//{
//	bool valid = false;
//	int x, y;
//	getCursorXY(x,y);
//	for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//	gotoXY(x,y);
//	do
//	{
//		cin >> entrada;
//
//		if (cin.fail())
//		{
//			cout << "Erro de leitura. Introduza uma entrada valida.\n";
//			cin.clear();
//		}
//		else
//			valid = true;
//
//		if (!valid)
//		{
//			gotoXY(x,y);
//			for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//			gotoXY(x,y);
//		}
//		cin.ignore(1000, '\n');
//	} while (!valid);
//}
//
//
//
//
//
//
///**
// * @brief Verifica se uma entrada e valida
// *
// *Verifica se o ID introduzido e valido
// *
// * @param Entrada pelo utilizador
// *
// */
//void getEntradaID(string &entrada)
//{
//	bool valid = false;
//	int x, y;
//
//	getCursorXY(x,y);
//	for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//	gotoXY(x,y);
//	do
//	{
//		getline(cin, entrada);
//
//		if (entrada.size() != 10)
//			cout << "Entrada invalida. Tem de ter exatamente 10 caracteres.\n";
//		else if (find(entrada.begin(), entrada.end(), '_') != entrada.end())
//			cout << "Entrada invalida. Nao pode usar underscores.\n";
//		else if (cin.fail())
//		{
//			cout << "Erro de leitura. Introduza uma entrada valida.\n";
//			cin.clear();
//		}
//		else
//			valid = true;
//
//		if (!valid)
//		{
//			gotoXY(x,y);
//			for (int x_clear = x; x_clear < 80; x_clear++) {cout << " ";};
//			gotoXY(x,y);
//		}
//	} while (!valid);
//}
//
//
//
//
//
//
///**
// * @brief Espera que o utilizador pressione uma tecla
// *
// *
// */
//void waitReturn()
//{
//	cout << "\nPressione ENTER para regressar. ";
//	cin >> noskipws;
//	cin.ignore(1000, '\n');
//	clrscr();
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao servicos
// *
// * @param Oficina
// *
// *
// */
//void ServicosHandler(Oficina &f)
//{
//	bool invalid = false;
//	int option;
//	do {
//		clrscr();
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1 - Adicionar servicos" << endl;
//		cout << "2 - Remover servicos" << endl;
//		cout << "3 - Ver servicos" << endl;
//		cout << "0 - Voltar" << endl;
//
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//		invalid = !(option >= 1 && option <= 3);
//
//		clrscr();
//		if (!invalid)
//		{
//			switch (option)
//			{
//			case 1:
//				try
//				{
//					addServicoHandler(f);
//				}
//				catch (ServicoRepetido &e) {
//					clearline();
//					cout << "Ocorreu um erro. Esse servico ja existe.\n";}
//				break;
//			case 2:
//				try
//				{
//					remServicoHandler(f);
//				}
//				catch (ServicoInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos um servico com esse nome\n.";}
//				break;
//			case 3:
//				clrscr();
//				f.MostrarServicos();
//				break;
//			}
//
//			waitReturn();
//		}
//	} while (option != 0);
//	clrscr();
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Clientes
// *
// * @param Oficina
// *
// *
// */
//void ClientesHandler(Oficina &f)
//{
//	bool invalid = false;
//	int option;
//	do {
//		clrscr();
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1 - Adicionar cliente" << endl;
//		cout << "2 - Remover cliente" << endl;
//		cout << "3 - Ver clientes ativos" << endl;
//		cout << "4 - Ver clientes inativos" << endl;
//		cout << "5 - Cartoes clientes" << endl;
//		cout << "0 - Voltar" << endl;
//
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//		invalid = !(option >= 1 && option <= 5);
//
//		clrscr();
//		if (!invalid)
//		{
//			switch (option)
//			{
//			case 1:
//				try
//				{
//					addClienteHandler(f);
//				} catch (ClienteRepetido &e) {
//					clearline();
//					cout << "Ocorreu um erro. Ja existe um cliente com esse ID.\n";}
//				waitReturn();
//				break;
//			case 2:
//				try {
//					remClienteHandler(f);
//				}
//				catch (ClienteInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos o cliente especificado.\n";}
//				waitReturn();
//				break;
//			case 3:
//				clrscr();
//				try{
//					MostrarClientesHandler(f);
//				}catch(ClienteInexistente &e){
//					clearline();
//					cout << "Ocorreu um erro. Nao temos o cliente especificado.\n";}
//				break;
//			case 4:
//				ClientesInativosHandler(f);
//				break;
//			case 5:
//				CartoesClienteHandler(f);
//				break;
//			}
//		}
//	} while (option != 0);
//	clrscr();
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Funcionarios
// *
// * @param Oficina
// *
// *
// */
//void FuncionariosHandler(Oficina &f)
//{
//	bool invalid = false;
//	int option;
//	do {
//		clrscr();
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1 - Adicionar funcionario" << endl;
//		cout << "2 - Remover funcionario" << endl;
//		cout << "3 - Empregado do mes" << endl;
//		cout << "4 - Ver funcionarios" << endl;
//		cout << "0 - Voltar" << endl;
//
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//		invalid = !(option >= 1 && option <= 4);
//
//		clrscr();
//		if (!invalid)
//		{
//			switch (option)
//			{
//			case 1:
//				try
//				{
//					addFuncionarioHandler(f);
//				}
//				catch (FuncionarioRepetido &e) {
//					clearline();
//					cout << "Ocorreu um erro. Ja existe um funcionario com esse ID.\n";}
//				catch (FuncaoInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao aceitamos funcionarios com essa funcao.\n";}
//				break;
//			case 2:
//				try {
//					remFuncionarioHandler(f);
//				}
//				catch (FuncionarioInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos o funcionario especificado.\n";}
//				break;
//			case 3:
//				clrscr();
//				EmpMesHandler(f);
//				break;
//			case 4:
//				try {
//					MostrarFuncsHandler(f);
//				}
//				catch(FuncionarioInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos o funcionario especificado.\n";}
//				break;
//			}
//
//			waitReturn();
//		}
//	} while (option != 0);
//	clrscr();
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Veiculos
// *
// * @param Oficina
// *
// *
// */
//void VeiculosHandler(Oficina &f)
//{
//	bool invalid = false;
//	int option;
//	do {
//		clrscr();
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1 - Adicionar veiculo" << endl;
//		cout << "2 - Adicionar servico a veiculo" << endl;
//		cout << "3 - Veiculo reparado" << endl;
//		cout << "4 - Cancelar reparacao" << endl;
//		cout << "5 - Ver veiculos" << endl;
//		cout << "6 - Historico" << endl;
//		cout << "0 - Voltar" << endl;
//
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//		invalid = !(option >= 1 && option <= 6);
//
//		clrscr();
//		if (!invalid)
//		{
//			switch (option)
//			{
//			case 1:
//				try
//				{
//					addVeiculoHandler(f);
//				}
//				catch (ClienteInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao encontramos o cliente na base de dados.\n";}
//				catch (VeiculoRepetido &e) {
//					clearline();
//					cout << "Ocorreu um erro. Ja existe um veiculo com essa matricula.\n";}
//				catch (NaoExistemMecanicos &e) {
//					clearline();
//					cout << "Nao pode adicionar o veiculo, pois nao temos mecanicos.\n";}
//				break;
//			case 2:
//				try
//				{
//					addSCHandler(f);
//				}
//				catch (VeiculoInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao existe nenhum veiculo com essa matricula.\n";}
//				catch (ServicoRepetido &e) {
//					clearline();
//					cout << "O veiculo ja possui esse servico associado.\n";}
//				break;
//			case 3:
//				try{
//					veicReparadoHandler(f);
//				}
//				catch (VeiculoInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos nenhum veiculo com essa matricula.\n";}
//				break;
//			case 4:
//				try {
//					remVeiculoHandler(f);
//				}
//				catch (VeiculoInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos nenhum veiculo com essa matricula.\n";}
//				break;
//			case 5:
//				clrscr();
//				f.MostrarVeiculos();
//				break;
//			case 6:
//				clrscr();
//				f.MostrarVeicsReps();
//				break;
//			}
//
//			waitReturn();
//		}
//	} while (option != 0);
//	clrscr();
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Marcacoes
// *
// * @param Oficina
// *
// *
// */
//void MarcacoesHandler(Oficina &f)
//{
//	bool invalid = false;
//	int option;
//	do {
//		clrscr();
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1 - Ver lista de marcacoes" << endl;
//		cout << "2 - Proxima marcacao a realizar" << endl;
//		cout << "3 - Concluir marcacao" << endl;
//		cout << "4 - Ver marcacoes dos proximos 7 dias" << endl;
//		cout << "5 - Alterar marcacao" << endl;
//		cout << "6 - Cancelar marcacao" << endl;
//		cout << "0 - Voltar" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//		invalid = !(option >= 1 && option <= 6);
//
//		clrscr();
//		if (!invalid)
//		{
//			switch (option)
//			{
//			case 1:
//				f.MostrarMarcacoes();
//				break;
//			case 2:
//				f.MostraProximaMarcacao();
//				break;
//			case 3:
//				f.removeMarcacao();
//				break;
//			case 4:
//				f.MostraMarcacoesSemana();
//				break;
//			case 5:
//				AlterarMarcacaoHandler(f);
//				break;
//			case 6:
//				CancelarMarcacaoHandler(f);
//				break;
//			}
//
//			waitReturn();
//		}
//	} while (option != 0);
//	clrscr();
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Mostrar Ficha Clientes
// *
// * @param Oficina
// * @param Cliente ativo ou inativo
// *
// *
// */
//void MostraFichaClienteHandler(Oficina &f, bool clienteAtivo)
//{
//	int counter = 0;
//	int n;
//	do{
//		clrscr();
//		if (clienteAtivo)
//			f.MostrarClientes();
//		else
//			f.MostrarClientesInativos();
//
//		if (counter != 0)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1- Introduzir por ID" << endl;
//		cout << "2- Introduzir por numero de cliente"<< endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(n);
//		counter++;
//	}while( (n != 1) && (n != 2) );
//	counter = 0;
//
//	cout << endl;
//
//	if( n == 1 ){
//		string ID;
//		cout << "Introduza ID do funcionario: ";
//		getEntradaID(ID);
//
//		std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//		clrscr();
//		if (clienteAtivo)
//		{
//			if (!f.existeCliente(ID))
//				throw ClienteInexistente();
//
//			f.mostraCliente(ID);
//		}
//		else
//		{
//			if (!f.existeClienteInativo(ID))
//				throw ClienteInexistente();
//
//			f.mostraClienteInativo(ID);
//		}
//	}
//	else{
//		int nCli;
//		cout << "Introduza numero do cliente: ";
//		getEntrada(nCli);
//
//
//		clrscr();
//		if (clienteAtivo)
//		{
//			if (!f.existeCliente(nCli))
//				throw ClienteInexistente();
//
//			f.mostraCliente(nCli);
//		}
//		else
//		{
//			if (!f.existeClienteInativo(nCli))
//				throw ClienteInexistente();
//
//			f.mostraClienteInativo(nCli);
//		}
//	}
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Adicionar Servico
// *
// * @param Oficina
// *
// *
// */
//void addServicoHandler(Oficina &f){
//	string nome, descricao;
//	float pBase,duracao;
//
//	clrscr();
//	cout << "Introduza nome do servico: ";
//	getEntrada(nome, SRV_NOMEMAX);
//
//	std::transform(nome.begin(), nome.end(), nome.begin(), to_lower_char);
//	if(f.existeServico(nome))
//		throw ServicoRepetido();
//
//	cout << "Introduza descricao: ";
//	getEntrada(descricao, SRV_DESCMAX);
//
//	cout << "Introduza preco: ";
//	getEntrada(pBase);
//
//	cout << "Introduza duracao: ";
//	getEntrada(duracao);
//
//	f.addServico(nome, descricao, pBase, duracao);
//}
//
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Adicionar Cliente
// *
// * @param Oficina
// *
// *
// */
//void addClienteHandler(Oficina &f){
//	string nome, ID, numTelemovel;
//	int NIF;
//
//	clrscr();
//	cout << "Introduza nome do cliente: ";
//	getEntrada(nome, PESSOA_NOMEMAX);
//	cout << "Introduza ID do cliente: ";
//	getEntradaID(ID);
//
//	std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//	if(f.existeCliente(ID) && f.existeClienteInativo(ID))
//		throw ClienteRepetido();
//
//	cout << "Introduza NIF do cliente: ";
//	getEntrada(NIF);
//
//	cout << "Introduza numero de contacto: ";
//	getEntrada(numTelemovel, 9);
//
//	f.addCliente(nome, ID, NIF, numTelemovel);
//}
//
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Adicionar Funcionario
// *
// * @param Oficina
// *
// *
// */
//void addFuncionarioHandler(Oficina &f){
//	string nome, ID, funcao;
//	int NIB, salario;
//
//	clrscr();
//	cout << "Introduza nome do funcionario: ";
//	getEntrada(nome, PESSOA_NOMEMAX);
//	cout << "Introduza ID do funcionario: ";
//	getEntradaID(ID);
//
//	std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//	if(f.existeFuncionario(ID))
//		throw FuncionarioRepetido();
//
//	cout << "Introduza NIB do funcionario: ";
//	getEntrada(NIB);
//	cout << "Introduza salario do funcionario: ";
//	getEntrada(salario);
//	cout << "Introduza funcao do funcionario: ";
//	getEntrada(funcao, FNC_FUNCAOMAX);
//
//	try {
//		f.addFuncionario(nome, ID, NIB, salario, funcao);
//	}
//	catch (FuncaoInexistente &e) {throw;}
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Adicionar Servico a um Veiculo
// *
// * @param Oficina
// *
// *
// */
//void addSCHandler(Oficina &f){
//	if (f.getNumVeiculos() == 0){
//		cout << "Nao existem veiculos" << endl;
//		return;
//	}
//	string matricula, nome, descricao;
//	string existe;
//	float precoBase, duracao;
//
//	clrscr();
//	f.MostrarServicos();
//	f.MostrarVeiculos();
//
//	cout << "Introduza matricula do veiculo: ";
//	getEntrada(matricula, VEIC_MATRMAX);
//	std::transform(matricula.begin(), matricula.end(), matricula.begin(), to_lower_char);
//	if (!f.existeVeiculo(matricula))
//		throw VeiculoInexistente();
//
//	cout << "Introduza nome do servico: ";
//	getEntrada(nome, SRV_NOMEMAX);
//	std::transform(nome.begin(), nome.end(), nome.begin(), to_lower_char);
//	if(f.existeServico(nome))
//	{
//		try {
//			f.addServicoCarro(matricula, nome);
//		}
//		catch (ServicoRepetido &e) {throw;}
//	}
//	else{
//		cout << "Introduza descricao do servico: ";
//		getEntrada(descricao, SRV_DESCMAX);
//		cout << "Introduza preco do servico : ";
//		getEntrada(precoBase);
//		cout << "Introduza duracao do servico: ";
//		getEntrada(duracao);
//
//		try {
//			f.addServicoCarro(matricula, nome, descricao, precoBase, duracao);
//		}
//		catch (ServicoRepetido &e) {throw;}
//	}
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Adicionar Veiculo
// *
// * @param Oficina
// *
// *
// */
//void addVeiculoHandler(Oficina &f){
//	int n, t, counter = 0;
//
//	clrscr();
//	if (!f.temMecanicos())
//		throw NaoExistemMecanicos();
//
//	do{
//		clrscr();
//		if (counter != 0)
//			cout << "Opcao invalida!" << endl << endl;
//
//		f.MostrarClientes();
//		cout << endl;
//		f.MostrarClientesInativos();
//		cout << "\n1- Introduzir por ID" << endl;
//		cout << "2- Introduzir por numero de cliente" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(n);
//		counter++;
//	}while( (n != 1) && (n != 2) );
//	counter = 0;
//
//	string ID, marca, matricula;
//	int nCliente;
//
//	if( n == 1 ){
//		cout << "Introduza ID do cliente: ";
//		getEntradaID(ID);
//
//		std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//		if(!f.existeCliente(ID) && !f.existeClienteInativo(ID))
//			throw ClienteInexistente();
//
//		do{
//			if(counter != 0)
//			{
//				clrscr();
//				cout << "Opcao invalida!" << endl;
//			}
//
//			cout << "\n1- Veiculo ligeiro" << endl;
//			cout << "2- Veiculo pesado" << endl;
//			cout << "Indique tipo de veiculo: ";
//			getEntrada(t);
//			counter++;
//		}while( (t != 1) && (t != 2) );
//		counter = 0;
//
//		cout << "\nIntroduza marca do veiculo: ";
//		getEntrada(marca,VEIC_MARCAMAX);
//		cout << "Introduza matricula do veiculo: ";
//		getEntrada(matricula,VEIC_MATRMAX);
//
//		std::transform(matricula.begin(), matricula.end(), matricula.begin(), to_lower_char);
//		if(f.existeVeiculo(matricula))
//			throw VeiculoRepetido();
//
//		if ( t == 2 ){
//			int comprimento, largura;
//			cout << "Introduza comprimento do veiculo: ";
//			getEntrada(comprimento);
//			cout << "Introduza largura do veiculo: ";
//			getEntrada(largura);
//
//			f.addVeiculo(ID, marca, matricula, comprimento, largura);
//		}
//		else{
//			f.addVeiculo(ID, marca, matricula);
//		}
//	}
//	else{
//		cout << "Introduza numero do cliente: ";
//		getEntrada(nCliente);
//
//		if(!f.existeCliente(nCliente) && !f.existeClienteInativo(nCliente))
//			throw ClienteInexistente();
//
//		do{
//			if(counter != 0)
//			{
//				clrscr();
//				cout << "Opcao invalida!" << endl;
//			}
//
//			cout << "\n1- Veiculo ligeiro" << endl;
//			cout << "2- Veiculo pesado" << endl;
//			cout << "Indique tipo de veiculo: ";
//			getEntrada(t);
//			counter++;
//		}while( (t != 1) && (t != 2) );
//		counter = 0;
//
//		cout << "\nIntroduza marca do veiculo: ";
//		getEntrada(marca,VEIC_MARCAMAX);
//		cout << "Introduza matricula do veiculo: ";
//		getEntrada(matricula,VEIC_MATRMAX);
//
//		std::transform(matricula.begin(), matricula.end(), matricula.begin(), to_lower_char);
//		if(f.existeVeiculo(matricula))
//			throw VeiculoRepetido();
//
//		if ( t == 2 ){
//			int comprimento, largura;
//
//			cout << "Introduza comprimento do veiculo: ";
//			getEntrada(comprimento);
//			cout << "Introduza largura do veiculo: ";
//			getEntrada(largura);
//
//			f.addVeiculo(nCliente, marca, matricula, comprimento, largura);
//		}
//		else{
//			f.addVeiculo(nCliente, marca, matricula);
//		}
//	}
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Lucro Previsto
// *
// * @param Oficina
// *
// *
// */
//void LPrevHandler(Oficina &f){
//	clrscr();
//	f.MostrarLP();
//	cout << "Lucro previsto: " << f.LucroPrevisto() << endl;
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Faturado
// *
// * @param Oficina
// *
// *
// */
//void FaturadoHandler(Oficina &f){
//	clrscr();
//	f.MostrarFaturado();
//	cout << "Faturado: " << f.Faturado() << endl;
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao remover Servico
// *
// * @param Oficina
// *
// *
// */
//void remServicoHandler(Oficina &f){
//	string nome;
//
//	clrscr();
//	f.MostrarServicos();
//	cout << "Introduza nome do servico a remover: ";
//	getEntrada(nome,SRV_NOMEMAX);
//
//	std::transform(nome.begin(), nome.end(), nome.begin(), to_lower_char);
//	if(!f.existeServico(nome))
//		throw ServicoInexistente();
//
//	f.remServico(nome);
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao remover Veiculo
// *
// * @param Oficina
// *
// *
// */
//void remVeiculoHandler(Oficina &f){
//	string matricula;
//
//	clrscr();
//	f.MostrarVeiculos();
//	cout << "Introduza matricula do veiculo: ";
//	getEntrada(matricula,VEIC_MATRMAX);
//
//	std::transform(matricula.begin(), matricula.end(), matricula.begin(), to_lower_char);
//	if(!f.existeVeiculo(matricula))
//		throw VeiculoInexistente();
//
//	f.remVeiculo(matricula, true);
//
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao remover Cliente
// *
// * @param Oficina
// *
// *
// */
//void remClienteHandler(Oficina &f){
//	int n, counter = 0;
//
//	do{
//		clrscr();
//		f.MostrarClientes();
//		cout << endl;
//		f.MostrarClientesInativos();
//		cout << endl;
//
//		if (counter != 0)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1- Introduzir por ID" << endl;
//		cout << "2- Introduzir por numero de cliente"<< endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(n);
//		counter++;
//	}while( (n != 1) && (n != 2) );
//	counter = 0;
//
//
//	string ID;
//	int nCliente;
//
//	if( n == 1 ){
//		cout << "Introduza ID do cliente: ";
//		getEntradaID(ID);
//
//		std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//		if(!f.existeCliente(ID) && !f.existeClienteInativo(ID))
//			throw ClienteInexistente();
//
//		f.remCliente(ID);
//	}
//	else{
//		cout << "Introduza numero do cliente: ";
//		getEntrada(nCliente);
//
//		if(!f.existeCliente(nCliente) && !f.existeClienteInativo(nCliente))
//			throw ClienteInexistente();
//
//		f.remCliente(nCliente);
//	}
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Veiculo Reparado
// *
// * @param Oficina
// *
// *
// */
//void veicReparadoHandler(Oficina &f){
//
//
//	clrscr();
//	if (f.getNumVeiculos() == 0){
//		cout << "Nao existem veiculos" << endl;
//		return;
//	}
//
//	string matricula;
//	f.MostrarVeiculos();
//	cout << "Introduza matricula do veiculo: ";
//	getEntrada(matricula,VEIC_MATRMAX);
//
//	std::transform(matricula.begin(), matricula.end(), matricula.begin(), to_lower_char);
//	if(!f.existeVeiculo(matricula))
//		throw VeiculoInexistente();
//
//	cout << "Veiculo reparado. Montante a pagar: " << f.veiculoReparado(matricula) << endl;
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao remover funcionario
// *
// * @param Oficina
// *
// *
// */
//void remFuncionarioHandler(Oficina &f){
//	int n, counter = 0;
//	string ID;
//	int nFunc;
//
//	do{
//		clrscr();
//		f.MostrarFuncionarios();
//		if (counter != 0)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1- Introduzir por ID" << endl;
//		cout << "2- Introduzir por numero de funcionario"<< endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(n);
//		counter++;
//	}while( (n != 1) && (n != 2) );
//	counter = 0;
//
//	if( n == 1 ){
//		cout << "Introduza ID do funcionario: ";
//		getEntradaID(ID);
//
//		std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//		if(!f.existeFuncionario(ID))
//			throw FuncionarioInexistente();
//
//		f.remFuncionario(ID);
//	}
//	else{
//		cout << "Introduza numero do funcionario: ";
//		getEntrada(nFunc);
//
//		if(!f.existeFuncionario(nFunc))
//			throw FuncionarioInexistente();
//
//		f.remFuncionario(nFunc);
//	}
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Empregado do Mes
// *
// * @param Oficina
// *
// *
// */
//void EmpMesHandler(Oficina &f){
//	int mes;
//	int counter=0;
//
//	do{
//		clrscr();
//		if(counter != 0)
//			cout << "Mes inexistente!" << endl;
//
//		cout << "Introduza mes: ";
//		getEntrada(mes);
//		counter++;
//	}while( mes<1 || mes>12);
//	counter = 0;
//
//	cout << endl << "Empregado do mes: " << f.EmpregadoDoMes(mes) << endl;
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Mostra Funcionarios
// *
// * @param Oficina
// *
// *
// */
//void MostrarFuncsHandler(Oficina &f)
//{
//	int opt;
//	int counter = 0;
//
//	do {
//		clrscr();
//		if (counter != 0)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1- Mostrar lista completa" << endl;
//		cout << "2- Restringir lista por salario" << endl;
//		cout << "3- Ver ficha de um funcionario" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(opt);
//		counter++;
//	} while ( (opt != 1) && (opt != 2) && (opt != 3) );
//
//	cout << endl;
//
//	if (opt == 1)
//	{
//		clrscr();
//		f.MostrarFuncionarios();
//	}
//	else if (opt == 2)
//	{
//		int lim_inf;
//		cout << "Indique o limite inferior para o salario: ";
//		getEntrada(lim_inf);
//		clrscr();
//		f.MostrarFuncionarios(lim_inf);
//	}
//	else if (opt == 3)
//	{
//		counter = 0;
//		int n;
//		do{
//			clrscr();
//			f.MostrarFuncionarios();
//			if (counter != 0)
//				cout << "Opcao invalida!" << endl;
//
//			cout << "1- Introduzir por ID" << endl;
//			cout << "2- Introduzir por numero de funcionario"<< endl;
//			cout << "Indique qual a opcao: ";
//			getEntrada(n);
//			counter++;
//		}while( (n != 1) && (n != 2) );
//		counter = 0;
//
//		cout << endl;
//
//		if( n == 1 ){
//			string ID;
//			cout << "Introduza ID do funcionario: ";
//			getEntradaID(ID);
//
//			std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//			if(!f.existeFuncionario(ID))
//				throw FuncionarioInexistente();
//
//			clrscr();
//			f.mostraFuncionario(ID);
//		}
//		else{
//			int nFunc;
//			cout << "Introduza numero do funcionario: ";
//			getEntrada(nFunc);
//
//			if(!f.existeFuncionario(nFunc))
//				throw FuncionarioInexistente();
//
//			clrscr();
//			f.mostraFuncionario(nFunc);
//		}
//	}
//}
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Mostra Clientes
// *
// * @param Oficina
// *
// *
// */
//void MostrarClientesHandler(Oficina &f){
//
//	clrscr();
//	bool invalid = false;
//	int option;
//	do {
//
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1- Mostrar lista completa" << endl;
//		cout << "2- Mostrar por NIF" << endl;
//		cout << "3- Restringir lista por alfabeto" << endl;
//		cout << "4- Ver ficha de um cliente" << endl;
//		cout << "0 - Voltar" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//
//		invalid = !(option >= 1 && option <= 4);
//		clrscr();
//
//		if (!invalid)
//		{
//			if (option == 1)
//				f.MostrarClientes();
//			else if (option == 2)
//			{
//				f.MostrarClientesNIF();
//			}
//			else if (option == 3)
//			{
//				string a;
//				string b;
//				cout << "Indique primeira letra: ";
//				getEntrada(a,1);
//				cout << "Indique a segunda letra: ";
//				getEntrada(b,1);
//
//				if (b < a)
//				{
//					cout << "A primeira letra tem que vir primeiro no alfabeto. Tente novamente.\n";
//					return;
//				}
//
//				clrscr();
//				f.MostrarClientes(a[0], b[0]);
//			}
//			else if (option == 4)
//			{
//				MostraFichaClienteHandler(f, true);
//			}
//
//			waitReturn();
//		}
//	} while (option != 0);
//	clrscr();
//}
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Mostra Clientes Inativos
// *
// * @param Oficina
// *
// *
// */
//void ClientesInativosHandler(Oficina &f)
//{
//	clrscr();
//	bool invalid = false;
//	int option;
//	do {
//
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1 - Mostrar lista completa" << endl;
//		cout << "2 - Ver ficha de um cliente" << endl;
//		cout << "3 - Atualizar informacao de um cliente" << endl;
//		cout << "4 - Listar por numero de anos inativo" << endl;
//		cout << "0 - Voltar" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//
//		invalid = !(option >= 1 && option <= 4);
//		clrscr();
//
//		if (!invalid)
//		{
//			if (option == 1)
//				f.MostrarClientesInativos();
//			else if (option == 2)
//			{
//				try {
//					MostraFichaClienteHandler(f, false);
//				} catch(ClienteInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos o cliente especificado.\n"; }
//			}
//			else if (option == 3)
//			{
//				try {
//					AtualizarInfoClienteInativo(f);
//				} catch(ClienteInexistente &e) {
//					clearline();
//					cout << "Ocorreu um erro. Nao temos o cliente especificado.\n"; }
//			}
//			else if (option == 4)
//			{
//				int N;
//				int counter =  0;
//				do {
//					if (counter != 0)
//					{
//						clrscr();
//						cout << "Opcao invalida!";
//					}
//					else
//						cout << "Indique o numero de anos de inatividade minimo: ";
//
//					getEntrada(N);
//					counter++;
//				} while(N <= 0);
//
//				f.MostrarClientesInativos(N);
//			}
//
//			waitReturn();
//		}
//	} while (option != 0);
//	clrscr();
//}
//
//
//
//
//
//
///**
// * @brief Verifica se a matricula e o servico sao validos para os pontos do Cartao Cliente
// *
// * @param Oficina
// * @param Cartao Cliente
// *
// *
// *return Numero de pontos a descontar ao cliente
// */
//int addSCHandler(Oficina &f, CartaoCliente cc){
//	string matricula, nome;
//
//	bool invalid = false;
//	do {
//		if (invalid)
//			cout << "Opcao invalida! Indique novamente: ";
//		else
//			cout << "Introduza matricula do veiculo: ";
//
//		invalid = false;
//		getEntrada(matricula, VEIC_MATRMAX);
//		std::transform(matricula.begin(), matricula.end(), matricula.begin(), to_lower_char);
//
//		if (!f.existeVeiculo(matricula))
//			invalid = true;
//	} while (invalid);
//
//
//	invalid = false;
//	do
//	{
//		if (invalid)
//			cout << "Opcao invalida! Indique novamente: ";
//		else
//			cout << "Introduza nome do servico: ";
//
//		getEntrada(nome, SRV_NOMEMAX);
//		std::transform(nome.begin(), nome.end(), nome.begin(), to_lower_char);
//		if(f.existeServico(nome, cc.getPontos()/2))
//		{
//			try {
//				f.addServicoCarro(matricula, nome);
//				invalid = false;
//			}
//			catch (ServicoRepetido &e) {
//				cout << "O veiculo ja possui esse servico - ";
//				invalid = true;}
//		}
//		else invalid = true;
//	} while (invalid);
//
//	return f.getPrecoServico(nome) * 2;
//}
//
//
//
//
//
//
//
///**
// * @brief Da display do menu para a opcao Cartoes Cliente
// *
// * @param Oficina
// *
// *
// */
//void CartoesClienteHandler (Oficina &f)
//{
//	clrscr();
//	bool invalid = false;
//	int option;
//	do {
//
//		if (invalid)
//			cout << "Opcao invalida!" << endl;
//
//		cout << "1 - Mostrar cartoes dos clientes" << endl;
//		cout << "2 - Oferecer promocao" << endl;
//		cout << "0 - Voltar" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//
//		invalid = !(option >= 1 && option <= 2);
//		clrscr();
//
//		if (!invalid)
//		{
//			if (option == 1)
//				f.MostrarCartoesCliente();
//			else if (option == 2)
//				AtualizarCartoesHandler(f);
//
//			waitReturn();
//		}
//	} while (option != 0);
//}
//
//
//
//
//
//
///**
// * @brief Permite a clientes com mais pontos usufruir de servicos ao seus veiculos
// *
// *  Permite a clientes com mais pontos usufruir de servicos ao seus veiculos e atualiza os cartoes devidamente
// *
// * @param Oficina
// *
// *
// */
//void AtualizarCartoesHandler(Oficina &f)
//{
//	priority_queue<CartaoCliente> ccs = f.getCartoesCliente();
//	list<CartaoCliente> lista_cc;
//	list<int> lista_pontos;
//	int minPreco = f.getPrecoMinimoServico();
//
//	clrscr();
//	int counter = 0;
//	bool enoughPoints = false;
//	while (counter < 5)
//	{
//		if (ccs.empty())
//			break;
//
//		CartaoCliente cc = ccs.top();
//		if (cc.getPontos() == 0)
//			break;
//		else if (cc.getPontos()/2 < minPreco)
//			break;
//
//		vector<string> matriculas;
//		cc.getCliente()->getMatriculaVeics(matriculas);
//
//		if (!matriculas.empty())
//		{
//			enoughPoints = true;
//			string resposta = "s";
//			do
//			{
//				if (resposta != "s" && resposta != "n")
//					cout << "Escreva 's' ou 'n'\n\n";
//				cout << "Numero de cliente: " << cc.getCliente()->getNCliente() << endl;
//				cout << "Nome: " << cc.getCliente()->getNome() << endl;
//				cout << "ID: " << cc.getCliente()->getID() << endl;
//				cout << "Contacto: " << cc.getCliente()->getNumTelemovel() << endl << endl;
//
//				cout << "Deseja utilizar pontos? (s/n): ";
//				getEntrada(resposta, 1);
//				clrscr();
//			} while (resposta != "s" && resposta != "n");
//
//
//			if (resposta == "s")
//			{
//				cc.getCliente()->mostrarVeics();
//				cout << endl << endl;
//				f.MostrarServicos(cc.getPontos()/2);
//
//				int pontos = addSCHandler(f, cc);
//				lista_cc.push_front(cc);
//				lista_pontos.push_front(pontos);
//				counter++;
//			}
//		}
//		ccs.pop();
//	}
//
//	f.atualizaCartoesCliente(lista_cc, lista_pontos);
//
//	if (enoughPoints)
//	{
//		if (counter != 0)
//		{
//			clrscr();
//			f.MostrarCartoesCliente();
//		}
//	}
//	else {
//		cout << "Nao tem clientes com pontos suficientes\n";
//	}
//}
//
//
//
//
//
//
///**
// * @brief Permite atualizar informacao relativa a um cliente inativo
// *
// * Permite atualizar um nome ou numero de telefone relativo a um cliente inativo
// *
// * @param Oficina
// *
// *
// */
//void AtualizarInfoClienteInativo(Oficina &f)
//{
//	int counter = 0;
//	int option;
//
//	do{
//		clrscr();
//		if (counter != 0)
//			cout << "Opcao invalida!" << endl << endl;
//
//		f.MostrarClientesInativos();
//		cout << "\n1- Introduzir por ID" << endl;
//		cout << "2- Introduzir por numero de cliente" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(option);
//		counter++;
//	}while( (option != 1) && (option != 2) );
//
//
//	string ID;
//	int nCliente;
//	if( option == 1 ){
//		cout << "Introduza ID do cliente: ";
//		getEntradaID(ID);
//
//		std::transform(ID.begin(), ID.end(), ID.begin(), to_lower_char);
//		if(!f.existeClienteInativo(ID))
//			throw ClienteInexistente();
//	}
//	else if ( option == 2 ) {
//		cout << "Introduza numero do cliente: ";
//		getEntrada(nCliente);
//
//		if(!f.existeClienteInativo(nCliente))
//			throw ClienteInexistente();
//	}
//
//
//	counter = 0;
//	int change;
//	do {
//		clrscr();
//		if (counter != 0)
//			cout << "Opcao invalida!" << endl << endl;
//
//		cout << "1- Alterar nome" << endl;
//		cout << "2- Alterar contacto" << endl;
//		cout << "Indique qual a opcao: ";
//		getEntrada(change);
//		counter++;
//	} while ( (change != 1) && (change != 2) );
//
//	if (change == 1)
//	{
//		string nome;
//		cout << "Indique o novo nome: ";
//		getEntrada(nome, PESSOA_NOMEMAX);
//
//		if (option == 1)
//			f.alteraClienteInfoNome(ID, nome);
//		else
//			f.alteraClienteInfoNome(nCliente, nome);
//	}
//	else {
//		string contacto;
//		cout << "Indique o novo contacto: ";
//		getEntrada(contacto, 9);
//
//		if (option == 1)
//			f.alteraClienteInfoContacto(ID, contacto);
//		else
//			f.alteraClienteInfoContacto(nCliente, contacto);
//	}
//}
//
//
//
//
//void CancelarMarcacaoHandler(Oficina &f)
//{
//	clrscr();
//	f.MostrarMarcacoes();
//	cout << endl << endl;
//
//	int counter = 0;
//	string matricula;
//	do {
//		if (counter != 0)
//			cout << "Opcao invalida! Indique novamente: ";
//		else
//			cout << "Indique a matricula do veiculo: ";
//
//		getEntrada(matricula, VEIC_MATRMAX);
//		if (f.existeVeiculoMarcacao(matricula))
//			break;
//		counter++;
//	} while (true);
//
//
//	counter = 0;
//	string servico;
//	do {
//		if (counter != 0)
//			cout << "Opcao invalida! Indique novamente: ";
//		else
//			cout << "Indique o servico a cancelar: ";
//
//		getEntrada(servico, SRV_NOMEMAX);
//		if (f.existeServicoVeiculo(matricula, servico))
//			break;
//		counter++;
//	} while (true);
//
//	f.cancelaMarcacao(matricula, servico);
//}
//
//
//
//
//void AlterarMarcacaoHandler(Oficina &f)
//{
//	clrscr();
//	f.MostrarMarcacoes();
//	cout << endl << endl;
//
//	int counter = 0;
//	string matricula;
//	do {
//		if (counter != 0)
//			cout << "Opcao invalida! Indique novamente: ";
//		else
//			cout << "Indique a matricula do veiculo: ";
//
//		getEntrada(matricula, VEIC_MATRMAX);
//		if (f.existeVeiculoMarcacao(matricula))
//			break;
//		counter++;
//	} while (true);
//
//
//	counter = 0;
//	string servico_old;
//	do {
//		if (counter != 0)
//			cout << "Opcao invalida! Indique novamente: ";
//		else
//			cout << "Indique o servico a cancelar: ";
//
//		getEntrada(servico_old, SRV_NOMEMAX);
//		if (f.existeServicoVeiculo(matricula, servico_old))
//			break;
//		counter++;
//	} while (true);
//
//	clrscr();
//	f.MostrarServicos();
//
//	counter = 0;
//	string servico_new;
//	do {
//		if (counter != 0)
//			cout << "Opcao invalida! Indique novamente: ";
//		else
//			cout << "Indique o novo servico: ";
//
//		getEntrada(servico_new, SRV_NOMEMAX);
//		if (f.existeServico(servico_new))
//			break;
//		counter++;
//	} while (true);
//
//	f.alterarMarcacao(matricula, servico_old, servico_new);
//}
