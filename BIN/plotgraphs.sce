RESULT_PATH = '/home/jyothish/Documents/jyothish/works/qt/simulation/BIN/results/';
PLOT_PATH = '/home/jyothish/Documents/jyothish/works/qt/simulation/BIN/results/plots/';

figures = ['singleslit_1';
'singleslit_2' ]

n = size(figures,'r')
for i = 1:n
    fig = figures(i,1);
    M = read_csv(RESULT_PATH+fig+'.csv')
    var = strtod(M)
    f1 = scf(i);
    clf();
    plot(var(1:$,1),var(1:$,2),'b')
    save(PLOT_PATH+fig+'.scg',f1)
    xs2bmp(f1,PLOT_PATH+fig+'.bmp');
end

disp(figures)
disp(size(figures))

