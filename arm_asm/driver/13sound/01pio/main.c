int main(int argc, char *argv[])
{
//	ac97_init(0x54000000, 20 * 44100 * 2);
	ac97_init();
	wm9714_init();
	
	play_music(0x54000000, 20 * 44100 * 2);
	return 0;
}
