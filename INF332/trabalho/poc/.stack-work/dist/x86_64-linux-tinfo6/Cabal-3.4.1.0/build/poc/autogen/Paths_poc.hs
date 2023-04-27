{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
{-# OPTIONS_GHC -Wno-missing-safe-haskell-mode #-}
module Paths_poc (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/lucasjoviniano/dev/UFV/INF332/trabalho/poc/.stack-work/install/x86_64-linux-tinfo6/5539a0c53b40a1914ef86997a5535c8f9cea1aa1a4f3f3accc37e0ae9390f15c/9.0.2/bin"
libdir     = "/home/lucasjoviniano/dev/UFV/INF332/trabalho/poc/.stack-work/install/x86_64-linux-tinfo6/5539a0c53b40a1914ef86997a5535c8f9cea1aa1a4f3f3accc37e0ae9390f15c/9.0.2/lib/x86_64-linux-ghc-9.0.2/poc-0.1.0.0-K08ubxsXzHT5PnEaIF1ujL-poc"
dynlibdir  = "/home/lucasjoviniano/dev/UFV/INF332/trabalho/poc/.stack-work/install/x86_64-linux-tinfo6/5539a0c53b40a1914ef86997a5535c8f9cea1aa1a4f3f3accc37e0ae9390f15c/9.0.2/lib/x86_64-linux-ghc-9.0.2"
datadir    = "/home/lucasjoviniano/dev/UFV/INF332/trabalho/poc/.stack-work/install/x86_64-linux-tinfo6/5539a0c53b40a1914ef86997a5535c8f9cea1aa1a4f3f3accc37e0ae9390f15c/9.0.2/share/x86_64-linux-ghc-9.0.2/poc-0.1.0.0"
libexecdir = "/home/lucasjoviniano/dev/UFV/INF332/trabalho/poc/.stack-work/install/x86_64-linux-tinfo6/5539a0c53b40a1914ef86997a5535c8f9cea1aa1a4f3f3accc37e0ae9390f15c/9.0.2/libexec/x86_64-linux-ghc-9.0.2/poc-0.1.0.0"
sysconfdir = "/home/lucasjoviniano/dev/UFV/INF332/trabalho/poc/.stack-work/install/x86_64-linux-tinfo6/5539a0c53b40a1914ef86997a5535c8f9cea1aa1a4f3f3accc37e0ae9390f15c/9.0.2/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "poc_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "poc_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "poc_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "poc_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "poc_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "poc_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
