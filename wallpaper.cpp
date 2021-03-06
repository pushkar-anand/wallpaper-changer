#include<iostream>
#include <unistd.h>
#include <experimental/filesystem>

using namespace std;
int wallpaper_count_start=0;
int main()
{
	vector<experimental::filesystem::directory_entry> pics;
	int no_of_wallpapers;
	int time_interval = 1; //time in minutes

	string wallpaperDIR = "/home/pushkar/Wallpapers"; //the directory where wallpapers are stored

	for (auto & p : experimental::filesystem::directory_iterator(wallpaperDIR))
	{
        	pics.push_back(p);
	}
	
	no_of_wallpapers = pics.size();
	
	// random selection of wallpaper
	if(wallpaper_count_start == 0) {
		cout<<"Random selection on start"<<endl;
		srand(time(NULL));
		wallpaper_count_start = 0 + (rand() % static_cast<int>(no_of_wallpapers - 0 + 1));
	}
	
	cout<<"Selected Wallpaper count: "<<wallpaper_count_start<<endl;
	
	
	string fileSTRING = pics[wallpaper_count_start].path().string();
	
	string cmd = "gsettings set org.gnome.desktop.background picture-uri \""+ fileSTRING +"\"";
	cout<<"Issuing cmd: "<<cmd<<endl;
	
	system(cmd.c_str());
	if(wallpaper_count_start== no_of_wallpapers-1 )
	{
		wallpaper_count_start=0;
	}
	else
	{
		wallpaper_count_start+=1;
	}
	
	int n = time_interval*60;
	sleep(n);
	main();
	
	/*for(auto it=pics.begin();it!=pics.end();it++)
		cout<<*it;*/

	return 0;
}
