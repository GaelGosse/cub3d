cp -f xpm_we_colors.c xpm_ea_colors.c && sed -i 's/we/ea/g' xpm_ea_colors.c
cp -f xpm_we_correction.c xpm_ea_correction.c && sed -i 's/we/ea/g' xpm_ea_correction.c
cp -f xpm_we_dual.c xpm_ea_dual.c && sed -i 's/we/ea/g' xpm_ea_dual.c
cp -f xpm_we_parse.c xpm_ea_parse.c && sed -i 's/we/ea/g' xpm_ea_parse.c
cp -f xpm_we_utils.c xpm_ea_utils.c && sed -i 's/we/ea/g' xpm_ea_utils.c

cp -f xpm_we_colors.c xpm_no_colors.c && sed -i 's/we/no/g' xpm_no_colors.c
cp -f xpm_we_correction.c xpm_no_correction.c && sed -i 's/we/no/g' xpm_no_correction.c
cp -f xpm_we_dual.c xpm_no_dual.c && sed -i 's/we/no/g' xpm_no_dual.c
cp -f xpm_we_parse.c xpm_no_parse.c && sed -i 's/we/no/g' xpm_no_parse.c
cp -f xpm_we_utils.c xpm_no_utils.c && sed -i 's/we/no/g' xpm_no_utils.c

cp -f xpm_we_colors.c xpm_so_colors.c && sed -i 's/we/so/g' xpm_so_colors.c
cp -f xpm_we_correction.c xpm_so_correction.c && sed -i 's/we/so/g' xpm_so_correction.c
cp -f xpm_we_dual.c xpm_so_dual.c && sed -i 's/we/so/g' xpm_so_dual.c
cp -f xpm_we_parse.c xpm_so_parse.c && sed -i 's/we/so/g' xpm_so_parse.c
cp -f xpm_we_utils.c xpm_so_utils.c && sed -i 's/we/so/g' xpm_so_utils.c

cp -f draw_xpm_down_we.c draw_xpm_down_ea.c && sed -i 's/we/ea/g' draw_xpm_down_ea.c
cp -f draw_xpm_down_we.c draw_xpm_down_no.c && sed -i 's/we/no/g' draw_xpm_down_no.c
cp -f draw_xpm_down_we.c draw_xpm_down_so.c && sed -i 's/we/so/g' draw_xpm_down_so.c

cp -f draw_xpm_up_we.c draw_xpm_up_ea.c && sed -i 's/we/ea/g' draw_xpm_up_ea.c
cp -f draw_xpm_up_we.c draw_xpm_up_no.c && sed -i 's/we/no/g' draw_xpm_up_no.c
cp -f draw_xpm_up_we.c draw_xpm_up_so.c && sed -i 's/we/so/g' draw_xpm_up_so.c
