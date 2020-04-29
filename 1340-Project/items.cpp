#include <vector>
using namespace std;

int items(int atk, int hp, int def) {
    
    cout << "Your items: " << 
	    for (int i = 0; i < itemsgot.size(); i++) {
		    cout << i << ". " << itemslist[itemsgot.at(i)] << endl;
    int use;
    cin >> use ;
    use=itemegot.at(use);
    if (use==1 || use==2 || use==0){
        cout << "Your attack power has increase by 5." << endl;
        atk+=5;
    }
    else if (use==3|| use==4){
        cout << "Your HP has increase by 10." << endl;
        hp+=10;
    }
    else{
        cout << "Your defense power has increase by 3." << endl;;
        def+=3;
    }
    itemsgot.erase(i)
    return atk, hp, def;
}
