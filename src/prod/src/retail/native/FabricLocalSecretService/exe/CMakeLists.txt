include_directories("..")

add_compile_options(-rdynamic)

add_definitions(-DBOOST_TEST_ENABLED)
add_definitions(-DNO_INLINE_EVENTDESCCREATE)

add_executable(${exe_FabricLSS}
  ../main.cpp
  )

add_precompiled_header(${exe_FabricLSS} ../stdafx.h)

set_target_properties(${exe_FabricLSS} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR}) 

add_custom_target(CopyFabricLSS ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${TEST_OUTPUT_DIR}/__FabricSystem_App4294967295/LSS.Code.Current
    COMMAND ${CMAKE_COMMAND} -E copy ${TEST_OUTPUT_DIR}/${exe_FabricLSS} ${TEST_OUTPUT_DIR}/__FabricSystem_App4294967295/CSS.Code.Current/FabricCSS.exe
    COMMAND ${CMAKE_STRIP} ${TEST_OUTPUT_DIR}/__FabricSystem_App4294967295/LSS.Code.Current/FabricLSS.exe
    DEPENDS ${exe_FabricLSS}
)

target_link_libraries(${exe_FabricLSS}
  ${lib_LocalSecretService}
  ${lib_FabricNode}
  ${lib_Communication}
  ${lib_ManagementSubsystem}
  ${lib_UpgradeService}
  ${lib_Client}
  ${lib_ManagementCommon}
  ${lib_HealthManager}
  ${lib_ClusterManager}
  ${lib_ImageStore}
  ${lib_EntreeService}
  ${lib_StoreService}
  ${lib_FabricGateway}
  ${lib_Hosting2}
  ${lib_Testability}
  ${lib_FileStoreService}
  ${lib_Store}
  ${lib_TestHooks}
  ${lib_KtlLogger}
  ${lib_TStore}
  ${lib_ApiWrappers}
  ${lib_StoreRepairPolicy}
  ${lib_Replication}
  ${lib_TransactionalReplicator}
  ${lib_Failover}
  ${lib_NetworkInventoryManager}
  ${lib_LoadBalancing}
  ${lib_SystemServices}
  ${lib_ServiceGroup}
  ${lib_ImageModel}
  ${lib_Query}
  ${lib_LeaseAgent}
  ${lib_Lease}
  ${lib_Federation}
  ${lib_ClientServerTransport}
  ${lib_Transport}
  ${lib_Client}
  ${lib_Common}
  ${lib_ServiceModel}
  ${lib_Serialization}
  ${lib_FabricRuntime}
  ${lib_FabricCommon}
  ${lib_InternalFabricUUID}
  ${lib_FabricUUID}
  ${lib_FabricResources}
  ${KtlUser}
  ${Cxx}
  ${CxxABI}
  ssh2
  ssl
  crypto
  m
  rt
  jemalloc
  pthread
  dl
  xml2
  uuid
)
