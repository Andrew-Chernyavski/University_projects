@echo off

if not exist results mkdir results
if not exist roughs mkdir roughs
CALL t32.exe mx m 1000 > %CD%\roughs\mx_m.txt
CALL min.pl roughs\mx_m.txt roughs\mx_min.txt


 rem B800000000 mov eax 0
CALL t32.exe mx m 1000 100 B800000000 > %CD%\roughs\B800000000_100.txt
CALL min.pl roughs\B800000000_100.txt roughs\B800000000_100_min.txt
CALL t32.exe mx m 1000 1000 B800000000 > %CD%\roughs\B800000000_1k.txt
CALL min.pl roughs\B800000000_1k.txt roughs\B800000000_1k_min.txt
CALL t32.exe mx m 1000 10000 B800000000 > %CD%\roughs\B800000000_10k.txt
CALL min.pl roughs\B800000000_10k.txt roughs\B800000000_10k_min.txt
CALL t32.exe mx m 1000 100000 B800000000 > %CD%\roughs\B800000000_100k.txt
CALL min.pl roughs\B800000000_100k.txt roughs\B800000000_100k_min.txt
CALL min_form.pl roughs\B800000000_100_min.txt roughs\B800000000_1k_min.txt roughs\B800000000_10k_min.txt roughs\B800000000_100k_min.txt roughs\mx_min.txt results\mov_eax_0_(B800000000).txt

 rem BB00000000 mov ebx 0
CALL t32.exe mx m 1000 100 BB00000000 > %CD%\roughs\BB00000000_100.txt
CALL min.pl roughs\BB00000000_100.txt roughs\BB00000000_100_min.txt
CALL t32.exe mx m 1000 1000 BB00000000 > %CD%\roughs\BB00000000_1k.txt
CALL min.pl roughs\BB00000000_1k.txt roughs\BB00000000_1k_min.txt
CALL t32.exe mx m 1000 10000 BB00000000 > %CD%\roughs\BB00000000_10k.txt
CALL min.pl roughs\BB00000000_10k.txt roughs\BB00000000_10k_min.txt
CALL t32.exe mx m 1000 100000 BB00000000 > %CD%\roughs\BB00000000_100k.txt
CALL min.pl roughs\BB00000000_100k.txt roughs\BB00000000_100k_min.txt
CALL min_form.pl roughs\BB00000000_100_min.txt roughs\BB00000000_1k_min.txt roughs\BB00000000_10k_min.txt roughs\BB00000000_100k_min.txt roughs\mx_min.txt results\mov_ebx_0_(BB00000000).txt

 rem 66B80000 mov ax 0
CALL t32.exe mx m 1000 100 66B80000 > %CD%\roughs\66B80000_100.txt
CALL min.pl roughs\66B80000_100.txt roughs\66B80000_100_min.txt
CALL t32.exe mx m 1000 1000 66B80000 > %CD%\roughs\66B80000_1k.txt
CALL min.pl roughs\66B80000_1k.txt roughs\66B80000_1k_min.txt
CALL t32.exe mx m 1000 10000 66B80000 > %CD%\roughs\66B80000_10k.txt
CALL min.pl roughs\66B80000_10k.txt roughs\66B80000_10k_min.txt
CALL t32.exe mx m 1000 100000 66B80000 > %CD%\roughs\66B80000_100k.txt
CALL min.pl roughs\66B80000_100k.txt roughs\66B80000_100k_min.txt
CALL min_form.pl roughs\66B80000_100_min.txt roughs\66B80000_1k_min.txt roughs\66B80000_10k_min.txt roughs\66B80000_100k_min.txt roughs\mx_min.txt results\mov_ax_0_(66B80000).txt

 rem 66BB0000 mov bx 0
CALL t32.exe mx m 1000 100 66BB0000 > %CD%\roughs\66BB0000_100.txt
CALL min.pl roughs\66BB0000_100.txt roughs\66BB0000_100_min.txt
CALL t32.exe mx m 1000 1000 66BB0000 > %CD%\roughs\66BB0000_1k.txt
CALL min.pl roughs\66BB0000_1k.txt roughs\66BB0000_1k_min.txt
CALL t32.exe mx m 1000 10000 66BB0000 > %CD%\roughs\66BB0000_10k.txt
CALL min.pl roughs\66BB0000_10k.txt roughs\66BB0000_10k_min.txt
CALL t32.exe mx m 1000 100000 66BB0000 > %CD%\roughs\66BB0000_100k.txt
CALL min.pl roughs\66BB0000_100k.txt roughs\66BB0000_100k_min.txt
CALL min_form.pl roughs\66BB0000_100_min.txt roughs\66BB0000_1k_min.txt roughs\66BB0000_10k_min.txt roughs\66BB0000_100k_min.txt roughs\mx_min.txt results\mov_bx_0_(66BB0000).txt

 rem 40 inc eax
CALL t32.exe mx m 1000 100 40 > %CD%\roughs\40_100.txt
CALL min.pl roughs\40_100.txt roughs\40_100_min.txt
CALL t32.exe mx m 1000 1000 40 > %CD%\roughs\40_1k.txt
CALL min.pl roughs\40_1k.txt roughs\40_1k_min.txt
CALL t32.exe mx m 1000 10000 40 > %CD%\roughs\40_10k.txt
CALL min.pl roughs\40_10k.txt roughs\40_10k_min.txt
CALL t32.exe mx m 1000 100000 40 > %CD%\roughs\40_100k.txt
CALL min.pl roughs\40_100k.txt roughs\40_100k_min.txt
CALL min_form.pl roughs\40_100_min.txt roughs\40_1k_min.txt roughs\40_10k_min.txt roughs\40_100k_min.txt roughs\mx_min.txt results\inc_eax_(40).txt

 rem 43 inc ebx
CALL t32.exe mx m 1000 100 43 > %CD%\roughs\43_100.txt
CALL min.pl roughs\43_100.txt roughs\43_100_min.txt
CALL t32.exe mx m 1000 1000 43 > %CD%\roughs\43_1k.txt
CALL min.pl roughs\43_1k.txt roughs\43_1k_min.txt
CALL t32.exe mx m 1000 10000 43 > %CD%\roughs\43_10k.txt
CALL min.pl roughs\43_10k.txt roughs\43_10k_min.txt
CALL t32.exe mx m 1000 100000 43 > %CD%\roughs\43_100k.txt
CALL min.pl roughs\43_100k.txt roughs\43_100k_min.txt
CALL min_form.pl roughs\43_100_min.txt roughs\43_1k_min.txt roughs\43_10k_min.txt roughs\43_100k_min.txt roughs\mx_min.txt results\inc_ebx_(43).txt

 rem 6640 inc ax
CALL t32.exe mx m 1000 100 6640 > %CD%\roughs\6640_100.txt
CALL min.pl roughs\6640_100.txt roughs\6640_100_min.txt
CALL t32.exe mx m 1000 1000 6640 > %CD%\roughs\6640_1k.txt
CALL min.pl roughs\6640_1k.txt roughs\6640_1k_min.txt
CALL t32.exe mx m 1000 10000 6640 > %CD%\roughs\6640_10k.txt
CALL min.pl roughs\6640_10k.txt roughs\6640_10k_min.txt
CALL t32.exe mx m 1000 100000 6640 > %CD%\roughs\6640_100k.txt
CALL min.pl roughs\6640_100k.txt roughs\6640_100k_min.txt
CALL min_form.pl roughs\6640_100_min.txt roughs\6640_1k_min.txt roughs\6640_10k_min.txt roughs\6640_100k_min.txt roughs\mx_min.txt results\inc_ax_(6640).txt

 rem 6643 inc bx
CALL t32.exe mx m 1000 100 6643 > %CD%\roughs\6643_100.txt
CALL min.pl roughs\6643_100.txt roughs\6643_100_min.txt
CALL t32.exe mx m 1000 1000 6643 > %CD%\roughs\6643_1k.txt
CALL min.pl roughs\6643_1k.txt roughs\6643_1k_min.txt
CALL t32.exe mx m 1000 10000 6643 > %CD%\roughs\6643_10k.txt
CALL min.pl roughs\6643_10k.txt roughs\6643_10k_min.txt
CALL t32.exe mx m 1000 100000 6643 > %CD%\roughs\6643_100k.txt
CALL min.pl roughs\6643_100k.txt roughs\6643_100k_min.txt
CALL min_form.pl roughs\6643_100_min.txt roughs\6643_1k_min.txt roughs\6643_10k_min.txt roughs\6643_100k_min.txt roughs\mx_min.txt results\inc_bx_(6643).txt

 rem 83C001 add eax 1
CALL t32.exe mx m 1000 100 83C001 > %CD%\roughs\83C001_100.txt
CALL min.pl roughs\83C001_100.txt roughs\83C001_100_min.txt
CALL t32.exe mx m 1000 1000 83C001 > %CD%\roughs\83C001_1k.txt
CALL min.pl roughs\83C001_1k.txt roughs\83C001_1k_min.txt
CALL t32.exe mx m 1000 10000 83C001 > %CD%\roughs\83C001_10k.txt
CALL min.pl roughs\83C001_10k.txt roughs\83C001_10k_min.txt
CALL t32.exe mx m 1000 100000 83C001 > %CD%\roughs\83C001_100k.txt
CALL min.pl roughs\83C001_100k.txt roughs\83C001_100k_min.txt
CALL min_form.pl roughs\83C001_100_min.txt roughs\83C001_1k_min.txt roughs\83C001_10k_min.txt roughs\83C001_100k_min.txt roughs\mx_min.txt results\add_eax_1_(83C001).txt

 rem 83C301 add ebx 1
CALL t32.exe mx m 1000 100 83C301 > %CD%\roughs\83C301_100.txt
CALL min.pl roughs\83C301_100.txt roughs\83C301_100_min.txt
CALL t32.exe mx m 1000 1000 83C301 > %CD%\roughs\83C301_1k.txt
CALL min.pl roughs\83C301_1k.txt roughs\83C301_1k_min.txt
CALL t32.exe mx m 1000 10000 83C301 > %CD%\roughs\83C301_10k.txt
CALL min.pl roughs\83C301_10k.txt roughs\83C301_10k_min.txt
CALL t32.exe mx m 1000 100000 83C301 > %CD%\roughs\83C301_100k.txt
CALL min.pl roughs\83C301_100k.txt roughs\83C301_100k_min.txt
CALL min_form.pl roughs\83C301_100_min.txt roughs\83C301_1k_min.txt roughs\83C301_10k_min.txt roughs\83C301_100k_min.txt roughs\mx_min.txt results\add_ebx_1_(83C301).txt

 rem 6683C001 add ax 1
CALL t32.exe mx m 1000 100 6683C001 > %CD%\roughs\6683C001_100.txt
CALL min.pl roughs\6683C001_100.txt roughs\6683C001_100_min.txt
CALL t32.exe mx m 1000 1000 6683C001 > %CD%\roughs\6683C001_1k.txt
CALL min.pl roughs\6683C001_1k.txt roughs\6683C001_1k_min.txt
CALL t32.exe mx m 1000 10000 6683C001 > %CD%\roughs\6683C001_10k.txt
CALL min.pl roughs\6683C001_10k.txt roughs\6683C001_10k_min.txt
CALL t32.exe mx m 1000 100000 6683C001 > %CD%\roughs\6683C001_100k.txt
CALL min.pl roughs\6683C001_100k.txt roughs\6683C001_100k_min.txt
CALL min_form.pl roughs\6683C001_100_min.txt roughs\6683C001_1k_min.txt roughs\6683C001_10k_min.txt roughs\6683C001_100k_min.txt roughs\mx_min.txt results\add_ax_1_(6683C001).txt

 rem 6683C301 add bx 1
CALL t32.exe mx m 1000 100 6683C301 > %CD%\roughs\6683C301_100.txt
CALL min.pl roughs\6683C301_100.txt roughs\6683C301_100_min.txt
CALL t32.exe mx m 1000 1000 6683C301 > %CD%\roughs\6683C301_1k.txt
CALL min.pl roughs\6683C301_1k.txt roughs\6683C301_1k_min.txt
CALL t32.exe mx m 1000 10000 6683C301 > %CD%\roughs\6683C301_10k.txt
CALL min.pl roughs\6683C301_10k.txt roughs\6683C301_10k_min.txt
CALL t32.exe mx m 1000 100000 6683C301 > %CD%\roughs\6683C301_100k.txt
CALL min.pl roughs\6683C301_100k.txt roughs\6683C301_100k_min.txt
CALL min_form.pl roughs\6683C301_100_min.txt roughs\6683C301_1k_min.txt roughs\6683C301_10k_min.txt roughs\6683C301_100k_min.txt roughs\mx_min.txt results\add_bx_1_(6683C301).txt

 rem 48 dec eax
CALL t32.exe mx m 1000 100 48 > %CD%\roughs\48_100.txt
CALL min.pl roughs\48_100.txt roughs\48_100_min.txt
CALL t32.exe mx m 1000 1000 48 > %CD%\roughs\48_1k.txt
CALL min.pl roughs\48_1k.txt roughs\48_1k_min.txt
CALL t32.exe mx m 1000 10000 48 > %CD%\roughs\48_10k.txt
CALL min.pl roughs\48_10k.txt roughs\48_10k_min.txt
CALL t32.exe mx m 1000 100000 48 > %CD%\roughs\48_100k.txt
CALL min.pl roughs\48_100k.txt roughs\48_100k_min.txt
CALL min_form.pl roughs\48_100_min.txt roughs\48_1k_min.txt roughs\48_10k_min.txt roughs\48_100k_min.txt roughs\mx_min.txt results\dec_eax_(48).txt

 rem 4B dec ebx
CALL t32.exe mx m 1000 100 4B > %CD%\roughs\4B_100.txt
CALL min.pl roughs\4B_100.txt roughs\4B_100_min.txt
CALL t32.exe mx m 1000 1000 4B > %CD%\roughs\4B_1k.txt
CALL min.pl roughs\4B_1k.txt roughs\4B_1k_min.txt
CALL t32.exe mx m 1000 10000 4B > %CD%\roughs\4B_10k.txt
CALL min.pl roughs\4B_10k.txt roughs\4B_10k_min.txt
CALL t32.exe mx m 1000 100000 4B > %CD%\roughs\4B_100k.txt
CALL min.pl roughs\4B_100k.txt roughs\4B_100k_min.txt
CALL min_form.pl roughs\4B_100_min.txt roughs\4B_1k_min.txt roughs\4B_10k_min.txt roughs\4B_100k_min.txt roughs\mx_min.txt results\dec_ebx_(4B).txt

 rem 6648 dec ax
CALL t32.exe mx m 1000 100 6648 > %CD%\roughs\6648_100.txt
CALL min.pl roughs\6648_100.txt roughs\6648_100_min.txt
CALL t32.exe mx m 1000 1000 6648 > %CD%\roughs\6648_1k.txt
CALL min.pl roughs\6648_1k.txt roughs\6648_1k_min.txt
CALL t32.exe mx m 1000 10000 6648 > %CD%\roughs\6648_10k.txt
CALL min.pl roughs\6648_10k.txt roughs\6648_10k_min.txt
CALL t32.exe mx m 1000 100000 6648 > %CD%\roughs\6648_100k.txt
CALL min.pl roughs\6648_100k.txt roughs\6648_100k_min.txt
CALL min_form.pl roughs\6648_100_min.txt roughs\6648_1k_min.txt roughs\6648_10k_min.txt roughs\6648_100k_min.txt roughs\mx_min.txt results\dec_ax_(6648).txt

 rem 664B dec bx
CALL t32.exe mx m 1000 100 664B > %CD%\roughs\664B_100.txt
CALL min.pl roughs\664B_100.txt roughs\664B_100_min.txt
CALL t32.exe mx m 1000 1000 664B > %CD%\roughs\664B_1k.txt
CALL min.pl roughs\664B_1k.txt roughs\664B_1k_min.txt
CALL t32.exe mx m 1000 10000 664B > %CD%\roughs\664B_10k.txt
CALL min.pl roughs\664B_10k.txt roughs\664B_10k_min.txt
CALL t32.exe mx m 1000 100000 664B > %CD%\roughs\664B_100k.txt
CALL min.pl roughs\664B_100k.txt roughs\664B_100k_min.txt
CALL min_form.pl roughs\664B_100_min.txt roughs\664B_1k_min.txt roughs\664B_10k_min.txt roughs\664B_100k_min.txt roughs\mx_min.txt results\dec_bx_(664B).txt

 rem 83E801 sub eax 1
CALL t32.exe mx m 1000 100 83E801 > %CD%\roughs\83E801_100.txt
CALL min.pl roughs\83E801_100.txt roughs\83E801_100_min.txt
CALL t32.exe mx m 1000 1000 83E801 > %CD%\roughs\83E801_1k.txt
CALL min.pl roughs\83E801_1k.txt roughs\83E801_1k_min.txt
CALL t32.exe mx m 1000 10000 83E801 > %CD%\roughs\83E801_10k.txt
CALL min.pl roughs\83E801_10k.txt roughs\83E801_10k_min.txt
CALL t32.exe mx m 1000 100000 83E801 > %CD%\roughs\83E801_100k.txt
CALL min.pl roughs\83E801_100k.txt roughs\83E801_100k_min.txt
CALL min_form.pl roughs\83E801_100_min.txt roughs\83E801_1k_min.txt roughs\83E801_10k_min.txt roughs\83E801_100k_min.txt roughs\mx_min.txt results\sub_eax_1_(83E801).txt

 rem 83EB01 sub ebx 1
CALL t32.exe mx m 1000 100 83EB01 > %CD%\roughs\83EB01_100.txt
CALL min.pl roughs\83EB01_100.txt roughs\83EB01_100_min.txt
CALL t32.exe mx m 1000 1000 83EB01 > %CD%\roughs\83EB01_1k.txt
CALL min.pl roughs\83EB01_1k.txt roughs\83EB01_1k_min.txt
CALL t32.exe mx m 1000 10000 83EB01 > %CD%\roughs\83EB01_10k.txt
CALL min.pl roughs\83EB01_10k.txt roughs\83EB01_10k_min.txt
CALL t32.exe mx m 1000 100000 83EB01 > %CD%\roughs\83EB01_100k.txt
CALL min.pl roughs\83EB01_100k.txt roughs\83EB01_100k_min.txt
CALL min_form.pl roughs\83EB01_100_min.txt roughs\83EB01_1k_min.txt roughs\83EB01_10k_min.txt roughs\83EB01_100k_min.txt roughs\mx_min.txt results\sub_ebx_1_(83EB01).txt

 rem 6683E801 sub ax 1
CALL t32.exe mx m 1000 100 6683E801 > %CD%\roughs\6683E801_100.txt
CALL min.pl roughs\6683E801_100.txt roughs\6683E801_100_min.txt
CALL t32.exe mx m 1000 1000 6683E801 > %CD%\roughs\6683E801_1k.txt
CALL min.pl roughs\6683E801_1k.txt roughs\6683E801_1k_min.txt
CALL t32.exe mx m 1000 10000 6683E801 > %CD%\roughs\6683E801_10k.txt
CALL min.pl roughs\6683E801_10k.txt roughs\6683E801_10k_min.txt
CALL t32.exe mx m 1000 100000 6683E801 > %CD%\roughs\6683E801_100k.txt
CALL min.pl roughs\6683E801_100k.txt roughs\6683E801_100k_min.txt
CALL min_form.pl roughs\6683E801_100_min.txt roughs\6683E801_1k_min.txt roughs\6683E801_10k_min.txt roughs\6683E801_100k_min.txt roughs\mx_min.txt results\sub_ax_1_(6683E801).txt

 rem 6683EB01 sub bx 1
CALL t32.exe mx m 1000 100 6683EB01 > %CD%\roughs\6683EB01_100.txt
CALL min.pl roughs\6683EB01_100.txt roughs\6683EB01_100_min.txt
CALL t32.exe mx m 1000 1000 6683EB01 > %CD%\roughs\6683EB01_1k.txt
CALL min.pl roughs\6683EB01_1k.txt roughs\6683EB01_1k_min.txt
CALL t32.exe mx m 1000 10000 6683EB01 > %CD%\roughs\6683EB01_10k.txt
CALL min.pl roughs\6683EB01_10k.txt roughs\6683EB01_10k_min.txt
CALL t32.exe mx m 1000 100000 6683EB01 > %CD%\roughs\6683EB01_100k.txt
CALL min.pl roughs\6683EB01_100k.txt roughs\6683EB01_100k_min.txt
CALL min_form.pl roughs\6683EB01_100_min.txt roughs\6683EB01_1k_min.txt roughs\6683EB01_10k_min.txt roughs\6683EB01_100k_min.txt roughs\mx_min.txt results\sub_bx_1_(6683EB01).txt

 rem 33C0 xor eax eax
CALL t32.exe mx m 1000 100 33C0 > %CD%\roughs\33C0_100.txt
CALL min.pl roughs\33C0_100.txt roughs\33C0_100_min.txt
CALL t32.exe mx m 1000 1000 33C0 > %CD%\roughs\33C0_1k.txt
CALL min.pl roughs\33C0_1k.txt roughs\33C0_1k_min.txt
CALL t32.exe mx m 1000 10000 33C0 > %CD%\roughs\33C0_10k.txt
CALL min.pl roughs\33C0_10k.txt roughs\33C0_10k_min.txt
CALL t32.exe mx m 1000 100000 33C0 > %CD%\roughs\33C0_100k.txt
CALL min.pl roughs\33C0_100k.txt roughs\33C0_100k_min.txt
CALL min_form.pl roughs\33C0_100_min.txt roughs\33C0_1k_min.txt roughs\33C0_10k_min.txt roughs\33C0_100k_min.txt roughs\mx_min.txt results\xot_eax_eax_(33C0).txt

 rem 33DB xor ebx ebx
CALL t32.exe mx m 1000 100 33DB > %CD%\roughs\33DB_100.txt
CALL min.pl roughs\33DB_100.txt roughs\33DB_100_min.txt
CALL t32.exe mx m 1000 1000 33DB > %CD%\roughs\33DB_1k.txt
CALL min.pl roughs\33DB_1k.txt roughs\33DB_1k_min.txt
CALL t32.exe mx m 1000 10000 33DB > %CD%\roughs\33DB_10k.txt
CALL min.pl roughs\33DB_10k.txt roughs\33DB_10k_min.txt
CALL t32.exe mx m 1000 100000 33DB > %CD%\roughs\33DB_100k.txt
CALL min.pl roughs\33DB_100k.txt roughs\33DB_100k_min.txt
CALL min_form.pl roughs\33DB_100_min.txt roughs\33DB_1k_min.txt roughs\33DB_10k_min.txt roughs\33DB_100k_min.txt roughs\mx_min.txt results\xor_ebx_ebx_(33DB).txt

 rem 6633C0 xor ax ax
CALL t32.exe mx m 1000 100 6633C0 > %CD%\roughs\6633C0_100.txt
CALL min.pl roughs\6633C0_100.txt roughs\6633C0_100_min.txt
CALL t32.exe mx m 1000 1000 6633C0 > %CD%\roughs\6633C0_1k.txt
CALL min.pl roughs\6633C0_1k.txt roughs\6633C0_1k_min.txt
CALL t32.exe mx m 1000 10000 6633C0 > %CD%\roughs\6633C0_10k.txt
CALL min.pl roughs\6633C0_10k.txt roughs\6633C0_10k_min.txt
CALL t32.exe mx m 1000 100000 6633C0 > %CD%\roughs\6633C0_100k.txt
CALL min.pl roughs\6633C0_100k.txt roughs\6633C0_100k_min.txt
CALL min_form.pl roughs\6633C0_100_min.txt roughs\6633C0_1k_min.txt roughs\6633C0_10k_min.txt roughs\6633C0_100k_min.txt roughs\mx_min.txt results\xor_ax_ax_(6633C0).txt

 rem 90 nop
CALL t32.exe mx m 1000 100 90 > %CD%\roughs\90_100.txt
CALL min.pl roughs\90_100.txt roughs\90_100_min.txt
CALL t32.exe mx m 1000 1000 90 > %CD%\roughs\90_1k.txt
CALL min.pl roughs\90_1k.txt roughs\90_1k_min.txt
CALL t32.exe mx m 1000 10000 90 > %CD%\roughs\90_10k.txt
CALL min.pl roughs\90_10k.txt roughs\90_10k_min.txt
CALL t32.exe mx m 1000 100000 90 > %CD%\roughs\90_100k.txt
CALL min.pl roughs\90_100k.txt roughs\90_100k_min.txt
CALL min_form.pl roughs\90_100_min.txt roughs\90_1k_min.txt roughs\90_10k_min.txt roughs\90_100k_min.txt roughs\mx_min.txt results\nop_(90).txt

del *.* /q