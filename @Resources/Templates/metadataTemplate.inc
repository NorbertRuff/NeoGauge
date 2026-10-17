; ============================================================
; Metadata Template
; Centralizes common metadata fields for all components
;
; REQUIRED VARIABLES:
;   componentName         - Display name of the component (shown in Rainmeter context menu)
;   componentInformation  - Description/information about the component
;                          Use pipe (|) to separate multiple lines
;
; OPTIONAL VARIABLES:
;   componentVersion      - Version number (defaults to 1.0 if not specified)
;
; USAGE:
;   Set variables before including this template:
;     @include0="#@#Templates\metadataTemplate.inc"
;
; EXAMPLE:
;   [Variables]
;   componentName=RSM | CPU Temperature
;   componentInformation=Displays CPU temperature using HWiNFO64. | HWiNFO64 must be running.
;   componentVersion=1.0
; ============================================================

[Metadata]
Name=#componentName#
Author=Norbert Ruff | Flying Hyrax | flyinghyrax.deviantart.com
Information=#componentInformation#
Version=#*componentVersion*#
License=Creative Commons BY-NC-SA 3.0

