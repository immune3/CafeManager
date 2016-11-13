extern vector<menu> men;extern vector<barista> bari;extern queue<order> ord;extern void load();extern void test();// Basic 단계 구현 시간 조건 없을 때 로드밸런싱 // 이후 시간 및 다른 조건 추가에 따른 로드 밸런싱도 상속을 통해 구현 // 원한다면 상속을 통해 확장시켜 구현할 수 있게 하기를 목표로 하고있음class BasicReader : public Reader {public : void read() {  load(); }};class BasicComputer : public Computer{private : public : void compute() {  loadBalancing(); } void loadBalancing() {  while (!isEmptyOrder()) {   order curOrd = selectOrder();   for (int i = 0; i < curOrd.getNumOfDrink(); i++)    distributeOrder(selectBarista());  } } bool isEmptyOrder() {  return ord.empty(); } order selectOrder() {  return ord.front(); } void distributeOrder(int selected) {  bari[selected].incNumOfCofMade();  ord.pop(); } int selectBarista() {  int min = 1000;  barista curBari;  int bariId;  for (int i = 0; i < bari.size(); i++)   if (min > bari[i].getNumOfCofMade())   {    min = bari[i].getNumOfCofMade();    curBari = bari[i];    bariId = i;   }  return bariId; }};class BasicWriter : public Writer {public : void write() {  test(); }};
