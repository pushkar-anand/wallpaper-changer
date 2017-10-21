#include<iostream>
#include <unistd.h>
#include <experimental/filesystem>

using namespace std;
int wallpaper_count_start=0;
int main()
{
	vector<experimental::filesystem::directory_entry> pics;
	int no_of_wallpapers;
	int time_interval = 5; //time in minutes

	string wallpaperDIR = "XXXXXXXXX/Wallpapers"; //the directory where wallpapers are stored

	for (auto & p : experimental::filesystem::directory_iterator(wallpaperDIR))
	{
        	pics.push_back(p);
	}
	
	no_of_wallpapers = pics.size();
	string fileSTRING = pics[wallpaper_count_start].path().string();
	
	string cmd = "gsettings set org.gnome.desktop.background picture-uri \""+ fileSTRING +"\"";
	
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
