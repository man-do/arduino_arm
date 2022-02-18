
(cl:in-package :asdf)

(defsystem "arduino_arm_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "jointCmd" :depends-on ("_package_jointCmd"))
    (:file "_package_jointCmd" :depends-on ("_package"))
    (:file "jointState" :depends-on ("_package_jointState"))
    (:file "_package_jointState" :depends-on ("_package"))
  ))