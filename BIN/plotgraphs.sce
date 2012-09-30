RESULT_PATH = 'results/';
PLOT_PATH = 'results/plots/';

figures = listfiles(RESULT_PATH + '*.csv')

disp(figures)

n = size(figures,'r')
for i = 1:n
    fig = figures(i,1);
    M = read_csv(fig)
    var = strtod(M)
    f1 = scf(i);
    clf();
    fig = strsplit(fig,'/');
    fig = fig($,1);
    title(strsubst(fig,'.csv',''));
    plot(var(1:$,1),var(1:$,2),'b')
    save(PLOT_PATH+ strsubst(fig,'.csv','.scg'),f1)
    xs2bmp(f1,PLOT_PATH+ strsubst(fig,'.csv','.bmp'));
end

