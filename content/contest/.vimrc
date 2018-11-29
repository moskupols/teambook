set nocp si aw ai is ts=2 sw=2 et tm=100 nu bg=dark
sy on
im jj <esc>

nmap <F6> :make %:r.exe<CR>
nmap <F10> :make %:r.exe<CR>:!for i in tests/??; do ./%:r.exe <$i >$i.out 2>$i.err; done

nmap <F8> :copen<CR>
nmap <S-F8> :cclose<CR>
nmap <F9> :cn<CR>
nmap <S-F9> :cp<CR>
