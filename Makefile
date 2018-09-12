LATEXCMD = pdflatex -shell-escape
export max_print_line = 1048576

.PHONY: help
help:
	@echo "Available commands are:"
	@echo "	make fast	- to build the pdf, quickly (only runs LaTeX once)"
	@echo "	make pdf	- to build the pdf"
	@echo "	make clean	- to clean up the build process"
	@echo "	make veryclean	- to clean up and remove teambook.pdf"
	@echo "	make help	- to show this information"
	@echo ""
	@echo "For more information see the file 'doc/README'"

.PHONY: fast
fast:
	cd build && $(LATEXCMD) teambook.tex </dev/null
	cp build/teambook.pdf teambook.pdf

.PHONY: pdf teambook
pdf: teambook
teambook: test-session.pdf
	cd build && $(LATEXCMD) teambook.tex && $(LATEXCMD) teambook.tex
	cp build/teambook.pdf teambook.pdf

.PHONY: clean
clean: 
	cd build && rm -f teambook.aux teambook.log teambook.tmp teambook.toc teambook.pdf teambook.ptc

.PHONY: veryclean
veryclean: clean
	rm -f teambook.pdf test-session.pdf

test-session.pdf: content/test-session/chapter.tex
	cd build && $(LATEXCMD) test-session.tex
	cp build/test-session.pdf test-session.pdf
