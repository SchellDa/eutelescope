FROM base/archlinux

ENV ILCSOFT /ilcsoft

RUN pacman -Syu --noconfirm
RUN pacman -S core/gcc extra/eigen extra/gsl extra/wget core/automake core/gcc-fortran extra/subversion extra/git extra/jdk8-openjdk extra/libx11 extra/libxpm extra/libxft extra/libxext extra/python2 extra/cmake core/which core/make core/tar --needed --noconfirm

RUN mkdir -p $ILCSOFT
RUN cd /usr/bin && ln -sf python2 python
RUN git clone -b dev-nocmake https://github.com/eutelescope/ilcinstall $ILCSOFT/ilcinstall
RUN cd $ILCSOFT/ilcinstall && git status

RUN $ILCSOFT/ilcinstall/ilcsoft-install -i -v $ILCSOFT/ilcinstall/examples/eutelescope/release-standalone.cfg

ENV EUTELESCOPE /ilcsoft/v01-19-02/Eutelescope/master/
ENV EUDAQ /ilcsoft/v01-19-02/Eutelescope/master/external/eudaq/v1.7-dev/
ENV ILCSOFT_CMAKE_ENV /ilcsoft/v01-19-02/ILCSoft.cmake.env.sh
ENV MILLEPEDEII /ilcsoft/v01-19-02/Eutelescope/master/external/millepede2/tags/V04-03-03
ENV MILLEPEDEII_VERSION tags/V04-03-03
ENV GEAR /ilcsoft/v01-19-02/gear/v01-06-eutel-pre
ENV MARLIN /ilcsoft/v01-19-02/Marlin/v01-09
ENV MARLIN_DLL ${EUTELESCOPE}/lib/libEutelescope.so:${EUTELESCOPE}/lib/libEutelProcessors.so:${EUTELESCOPE}/lib/libEutelReaders.so:${EUDAQ}/lib/libNativeReader.so:${MARLIN_DLL}
ENV ROOTSYS /ilcsoft/v01-19-02/root/6.10.04
ENV GBL /ilcsoft/v01-19-02/GBL/V02-01-02
ENV PATH ${ROOTSYS}/bin:${MARLIN}/bin:${MILLEPEDEII}:${EUTELESCOPE}/bin:${GEAR}/tools:${GEAR}/bin:${PATH}
ENV LD_LIBRARY_PATH ${EUTELESCOPE}/lib:${ROOTSYS}/lib:${EUDAQ}/lib:${GEAR}/lib:${GBL}/lib:${LD_LIBRARY_PATH}

WORKDIR ${EUTELESCOPE}/build/
RUN make clean
CMD /bin/bash -c "echo $PR_NO; git fetch origin refs/pull/$PR_NO/merge; git checkout FETCH_HEAD; cmake ..; make install -j 4"

#RUN mkdir -p output/lcio output/logs output/histograms output/database
#RUN mkdir -p /afs/
#CMD jobsub -c config.cfg -csv runlist.csv -g converter 1085

