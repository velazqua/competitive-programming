/* Name: Alex Velazquez
 * Start Date: October 11, 2011 @ 12:54AM
 * End Date:   October 11, 2011 @ ??:??AM
*/

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	for (int i=0;i<T;++i)
	{
		double a,b,c,d,h,f,nextH,nextF;
		cin >> a >> b >> c >> d >> h >> f;
		//cout << "Case #" << i+1 << endl;
		int nH[2], nF[2];
		nH[0]=0; nH[1]=0; nF[0]=0; nF[1]=0;
		for (int k=0;k<20;++k)
		{
			nextH=a*h-b*f;
			nextF=c*f+d*h;
			if (nextH > h) // its increasing
				++nH[0];
			else if (nextH < h) // decreasing
				++nH[1];
			if (nextF > f) // its increasing
				++nF[0];
			else if (nextF < f) // decreasing
				++nF[1];
			//cout << "H_y+1 = " << nextH << ". F_y+1 = " << nextF << endl;
			h=nextH;
			f=nextF;
		}
		//cout << "nH: " << nH[0] << "," << nH[1] << endl;
		//cout << "nF: " << nF[0] << "," << nF[1] << endl;
		if (nextH < 0.5 && nextH > -0.5 && nextF < 0.5 && nextF > -0.5)
			cout << "Ecological balance will develop." << endl;
		else if (nH[0]+5 < nH[1] && nF[0] > nF[1]+5)
			cout << "Hares will die out while foxes will overgrow." << endl;
		else if (nH[0] > nH[1]+5 && nF[0]+5 < nF[1])
			cout << "Hares will overgrow while foxes will die out." << endl;
		else if (nH[0]+5 < nH[1] && nF[0]+5 < nF[1])
			cout << "Both hares and foxes will die out." << endl;
		else if (nH[0] > 5+nH[1] && nF[0] > 5+nF[1])
			cout << "Both hares and foxes will overgrow." << endl;
		else
			cout << "Chaos will develop." << endl;
	}
}
