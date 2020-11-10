int main()
{
    float x = 0.5;
    float y = 0.0;
	if (x < -1) {
		y = -x - 1;
		}
	if (x >= -1 && x <= 0) {
		y = x + 1;
		}
	if (x > 0 && x < 1) {
		y = -x + 1;
		}
	if (x >= 1){
		y = x - 1;
		}
    return 0;
}
